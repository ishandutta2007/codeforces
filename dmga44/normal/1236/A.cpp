#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pii;
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int res=0,sss=0;
        for(int i=0;i<=min(b/2,a);i++)
        {
            res=0;
            res+=(i*3);
            int x=c/2;
            res+=3*min(x,b-(2*i));
            sss=max(sss,res);
        }
        db(sss)
    }

    return 0;
}