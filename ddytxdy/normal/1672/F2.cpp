#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int T,n,a[N],b[N],d[N],cnt[N],mx,id,st[N],tp;
vector<int>v[N];
void solve(){
  scanf("%d",&n);mx=0;
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]),cnt[a[i]]++;
  for(int i=1;i<=n;i++)
    scanf("%d",&b[i]);
  for(int i=1;i<=n;i++)
    if(cnt[i]>mx)mx=cnt[i],id=i;
  for(int i=1;i<=n;i++)
    if(a[i]!=id)
      v[a[i]].pb(b[i]),d[b[i]]++;
  for(int i=1;i<=n;i++)
    if(!d[i])st[++tp]=i;
  while(tp){
    int x=st[tp--];
    for(int i=0;i<v[x].size();i++){
      int y=v[x][i];
      if(!--d[y])st[++tp]=y;
    }
  }
  bool fl=0;
  for(int i=1;i<=n;i++){
    if(d[i])fl=1;
    v[i].clear();
    cnt[i]=0;d[i]=0;
  }
  puts(fl?"WA":"AC");
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}