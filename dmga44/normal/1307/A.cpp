#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 105

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,d;
        cin >> n >> d;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(i)
            {
                int k=max(0,min(d/i,a[i]));
                a[0]+=k;
                d-=k*i;
            }
        }
        db(a[0])
    }

    return 0;
}