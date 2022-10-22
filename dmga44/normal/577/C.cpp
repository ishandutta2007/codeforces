#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
#define MAXN 1005

bool mk[MAXN],mk1[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!mk[i])
        {
            mk1[i]=1;
            for(int j=2*i;j<MAXN;j+=i)
            {
                if(!mk1[j/i])
                    mk[j]=1;
                else if((j/i)%i==0)
                    mk1[j]=1;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n;
    cin >> n;
    if(n==1)
    {
        db(0)
        return 0;
    }

    criba();

    vector<int> res;
    for(int i=0;i<=n;i++)
        if(mk1[i])
            res.push_back(i);

    db(res.size())
    for(auto y : res)
        cout << y << ' ';
    cout << '\n';

    return 0;
}