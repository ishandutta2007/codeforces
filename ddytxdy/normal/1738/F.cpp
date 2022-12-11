#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL long long
using namespace std;
const int N=2e5+50,mod=998244353,inv2=5e8+4;
const int M=1e5;
int T,n,d[N],id[N],cnt,c[N],a[N],tp;bool vis[N];
bool cmp(int x,int y){
  return d[x]>d[y];
}
void solve(){
  scanf("%d",&n);cnt=0;
  for(int i=1;i<=n;i++)
    scanf("%d",&d[i]),id[i]=i,vis[i]=c[i]=0;
  sort(id+1,id+n+1,cmp);
  for(int i=1;i<=n;i++){
    int x=id[i];
    if(vis[x])continue;
    a[tp=1]=x;
    int fl=0;
    for(int j=1,y;j<=d[x];j++){
      printf("? %d\n",x);
      cout.flush();
      scanf("%d",&y);
      if(vis[y]){fl=c[y];break;}
      else a[++tp]=y;
    }
    if(!fl)fl=++cnt;
    for(int j=1;j<=tp;j++)
      c[a[j]]=fl,vis[a[j]]=1;
  }
  printf("! ");
  for(int i=1;i<=n;i++)
    printf("%d ",c[i]);
  puts("");
  cout.flush();
}
int main(){
  // freopen("in.txt","r",stdin);
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}