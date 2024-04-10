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
#define MAXN 5005

int a[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        bool res=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<=n;j++)
                mk[j]=0;
            for(int j=0;j<i;j++)
                mk[a[j]]=1;
            for(int j=i+1;j<n;j++)
                if(mk[a[j]])
                    res=1;
        }

        if(res)
            db("YES")
        else
            db("NO")
    }

    return 0;
}