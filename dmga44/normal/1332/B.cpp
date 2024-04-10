#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 1005

int a[MAXN],res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(11);
    primes.push_back(13);
    primes.push_back(17);
    primes.push_back(19);
    primes.push_back(23);
    primes.push_back(29);
    primes.push_back(31);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            res[i]=0;
            cin >> a[i];
            for(auto y : primes)
                if(!(a[i]%y))
                {
                    s.insert(y);
                    break;
                }
        }

        int cont=1;
        for(auto y: s)
        {
            for(int i=0;i<n;i++)
                if(!(a[i]%y) && !res[i])
                    res[i]=cont;
            cont++;
        }

        db(cont-1)
        for(int i=0;i<n;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}
/**
2
3
6 10 15
2
4 9
**/