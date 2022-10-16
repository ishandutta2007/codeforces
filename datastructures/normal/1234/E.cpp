#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int n,m,a[200005];
int ch[200005],s,ans[200005];
signed main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++)scanf("%lld",&a[i]);
    for (int i=1;i<m;i++){
        s+=abs(a[i]-a[i+1]);
    }
    for (int i=1;i<=n;i++)ans[i]=s;
    for (int i=1;i<m;i++){
        int x=a[i],y=a[i+1];
        if (x>y)swap(x,y);
        if (x==y)continue;
        if (y-x==1){
            ans[x]+=y-1,ans[x]-=y-x;
            ans[y]+=(x+1)-1,ans[y]-=y-x;
            continue;
        }
        ans[x]+=y-1,ans[x]-=y-x;
        ans[y]+=(x+1)-1,ans[y]-=y-x;
        ch[x+1]--,ch[y]++;
    }
    for (int i=1;i<=n;i++)ch[i]+=ch[i-1];
    for (int i=1;i<=n;i++){
        ans[i]+=ch[i];
        printf("%lld ",ans[i]);
    }
    cout<<endl;
    return 0;
}