#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
struct node{
int l,r,size,fa,key;
}fhq[1000005];
int cnt,x,y,z,root;
inline void newnode(){
cnt++;
fhq[cnt].l=fhq[cnt].r=fhq[cnt].fa=0;
fhq[cnt].size=1;
fhq[cnt].key=rand()*rand()+rand();
return;
}
inline void update(register int now){
if (now==0)return;
fhq[now].size=fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
fhq[fhq[now].l].fa=fhq[fhq[now].r].fa=now;
return;
}
inline void split(register int now,register int val,register int &x,register int &y){
if (now==0){
x=y=0;
return;
}
if (fhq[fhq[now].l].size+1<=val){
x=now;
split(fhq[now].r,val-(fhq[fhq[now].l].size+1),fhq[now].r,y);
}
else{
y=now;
split(fhq[now].l,val,x,fhq[now].l);
}
update(now);
return;
}
inline int merge(register int x,register int y){
if (x==0)return y;
if (y==0)return x;
if (fhq[x].key>fhq[y].key){
fhq[x].r=merge(fhq[x].r,y);
update(x);
return x;
}
else{
fhq[y].l=merge(x,fhq[y].l);
update(y);
return y;
}
return 0;
}
inline int askid(register int now){
register int ans=1+fhq[fhq[now].l].size;
while(fhq[now].fa){
int f=fhq[now].fa;
if (now==fhq[f].r)ans+=fhq[fhq[f].l].size+1;
now=f;
}
return ans;
}
int n,m,s,ans[1000005][2];
int main(){
//	freopen("1288E.in","r",stdin);
//	freopen("1288E.out","w",stdout);
srand(time(NULL));
cin>>n>>m;
for (int i=1;i<=n;i++){
newnode();
root=merge(root,cnt);
}
for (int i=1;i<=n;i++)ans[i][0]=ans[i][1]=i;
for (int i=1;i<=m;i++){
scanf("%d",&s);
register int id=askid(s);
ans[s][0]=1,ans[s][1]=max(ans[s][1],id);
split(root,id-1,x,y);
split(y,1,y,z);
root=merge(y,merge(x,z));
}
for (int i=1;i<=n;i++)ans[i][1]=max(ans[i][1],askid(i));
for (int i=1;i<=n;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
return 0;
}