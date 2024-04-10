#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int t,x[5],y[5],c[5],book[5],ans;
struct Seg{
int l,r;
Seg(){
l=r=0;
return;
}
}a,b,ca,cb;
inline Seg calc(Seg a,Seg b){
Seg ans;
if (a.l>a.r)swap(a.l,a.r);
if (b.l>b.r)swap(b.l,b.r);
if (a.l>b.l)swap(a,b);
ans.l=max(0ll,b.l-a.r);
ans.r=max(a.r-b.l,b.r-a.l);
return ans;
}
inline void dfs(int now){
if (now>4){
int nows=abs(y[c[1]]-y[c[2]])+abs(y[c[3]]-y[c[4]])+abs(x[c[1]]-x[c[4]])+abs(x[c[2]]-x[c[3]]);
a.l=x[c[1]],a.r=x[c[4]];
b.l=x[c[2]],b.r=x[c[3]];
ca=calc(a,b);
a.l=y[c[1]],a.r=y[c[2]];
b.l=y[c[3]],b.r=y[c[4]];
cb=calc(a,b);
if (ca.l>cb.l)swap(ca,cb);
if (ca.r<cb.l)nows+=2*(cb.l-ca.r);
ans=min(ans,nows);
return;
}
for (int i=1;i<=4;i++){
if (book[i]==0){
book[i]=1;
c[now]=i;
dfs(now+1);
c[now]=0;
book[i]=0;
}
}
return;
}
signed main(){
cin>>t;
while(t--){
for (int i=1;i<=4;i++)scanf("%lld%lld",&x[i],&y[i]);
ans=1e18;
dfs(1);
cout<<ans<<endl;
}
}