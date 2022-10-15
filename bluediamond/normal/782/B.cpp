#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=60000+5;
int n,v[N],sp[N];

ld dst(ld point)
{
    ld ans=0;
    for(int j=1;j<=n;j++)
    {
        ld dist=abs((ld)point-v[j]);
        ld speed=sp[j];
        ans=max(ans,dist/speed);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>sp[i];
    ld st=0,dr=1000000000;
    for(int j=1;j<=100;j++)
    {
        ld med=(st+dr)*0.5;
        if(dst(med)>=dst(med+0.000001))
        {
            st=med;
        }
        else
        {
            dr=med;
        }
    }
    cout<<fixed<<setprecision(6)<<dst(st)<<"\n";
    return 0;
}
/**


**/