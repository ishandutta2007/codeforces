#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,m,x,k,y,a[200005],b[200005],pos[200005],ans;
signed main(){cin>>n>>m;cin>>x>>k>>y;for (int i=1;i<=n;i++)scanf("%lld",&a[i]);for (int i=1;i<=m;i++)scanf("%lld",&b[i]);for (int i=1;i<=m;i++){int now=pos[i-1];while(a[now]!=b[i]&&now<=n)now++;if (now>n){cout<<-1<<endl;return 0;}pos[i]=now;}pos[m+1]=n+1;for (int i=1;i<=m+1;i++){if (pos[i]-pos[i-1]==1)continue;int l=pos[i-1]+1,r=pos[i]-1;int len=r-l+1,mx=0;for (int j=l;j<=r;j++)mx=max(mx,a[j]);if (len<k){if (mx>a[l-1]&&mx>a[r+1]){cout<<-1<<endl;return 0;}ans+=len*y;}else{if (y*k<x){if (mx<a[l-1]||mx<a[r+1])ans+=y*len;else ans+=x+y*(len-k);}else{ans+=len/k*x;ans+=len%k*y;}}}cout<<ans<<endl;return 0;}