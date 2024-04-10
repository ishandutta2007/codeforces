#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t[7];
    t[0]=0;
    t[1]=1;
    t[2]=2;
    t[3]=0;
    t[4]=2;
    t[5]=1;
    t[6]=0;
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    ll m=min(a[0]/3,min(a[1]/2,a[2]/2));
    a[0]-=3*m;
    a[1]-=2*m;
    a[2]-=2*m;
    ll res=0;
    for(int i=0;i<7;i++)
    {
        ll b[3];
        for(int j=0;j<3;j++)
            b[j]=a[j];
        ll p=0;
        while(1)
        {
            if(!b[t[(i+p)%7]])
                break;
            b[t[(i+p)%7]]--;
            p++;
        }
        res=max(res,p);
    }
    db(res+(7*m))

    return 0;
}