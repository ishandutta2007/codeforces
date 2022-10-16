#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,a,b,c,ans;
signed main(){
 //   freopen("a.in","r",stdin);
 //   freopen("a.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        ans=0;
        if (a>0)a--,ans++;
        if (b>0)b--,ans++;
        if (c>0)c--,ans++;
        if (a<b)swap(a,b);
        if (a<c)swap(a,c);
        if (b<c)swap(b,c);
        if (a>0&&b>0)a--,b--,ans++;
        if (a>0&&c>0)a--,c--,ans++;
        if (b>0&&c>0)b--,c--,ans++;
        if (a>0&&b>0&&c>0)a--,b--,c--,ans++;
        cout<<ans<<endl;
    }
    return 0;
}