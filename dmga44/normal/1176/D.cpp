#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;;
#define MAXN 3000005

int p[MAXN];
int f[MAXN];
vector<int> primes;

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
        {
            primes.push_back(i);
            for(int j=i*2;j<MAXN;j+=i)
                if(!p[j])
                    p[j]=i;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int n,x;
    cin >> n;
    for(int i=0;i<2*n;i++)
    {
        cin >> x;
        f[x]++;
    }

    vector<int> res;
    for(int i=MAXN;i>=0;i--)
        if(p[i] && f[i])
        {
            while(f[i])
            {
                res.push_back(i);
                f[i]--;
                f[i/p[i]]--;
            }
        }

    for(int i=2;i<MAXN;i++)
        if(!p[i] && f[i])
        {
            while(f[i])
            {
                res.push_back(i);
                f[i]--;
                f[primes[i-1]]--;
            }
        }

    for(auto y : res)
        cout << y << ' ';
    cout << '\n';


    return 0;
}