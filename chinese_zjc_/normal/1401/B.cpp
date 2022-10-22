//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int T,x1,x2,y1,y2,z1,z2,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        ans=0;
        int tmp=min(z1,y2);
        ans=tmp*2;
        z1-=tmp;
        y2-=tmp;
        tmp=min(x2+y2,y1);
        // cout<<x1<<' '<<y1<<' '<<z1<<endl;
        // cout<<x2<<' '<<y2<<' '<<z2<<endl;
        y1-=tmp;
        int tmp2=min(x2,tmp);
        x2-=tmp2;
        y2-=tmp-tmp2;
        tmp=min(x1,z2);
        x1-=tmp;
        z2-=tmp;
        ans-=min(y1,z2)*2;
        cout<<ans<<endl;
    }
    return 0;
}