#include<bits/stdc++.h>
#define LL long long
#define pli pair<LL,int>
using namespace std;
const int N=1e3+50;
int T,n,k,nxt[N][N];char c[N][N],d[N][N];bool vis[N][N];
void solve(){
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)
    scanf("%s",c[i]+1);
  for(int j=1;j<=n;j++)
    for(int i=1;i<=n;i++){
      vis[i][j]=0;
      nxt[i][j]=c[i-1][j]=='0'?i-1:nxt[i-1][j];
    }
  for(int i=1;i<k;i++){
    int x=n,y=i;
    while(x!=1||y!=n+i-k+1){
      vis[x][y]=1;
      if(x-1>n+i-k){x--;continue;}
      if(y-1==n+i-k){x--;continue;}
      if(nxt[x][y]==0||vis[nxt[x][y]][y])y++;
      else x--;
    }
    vis[1][n+i-k+1]=1;
  }
  for(int i=1;i<=n;d[i++][n+1]='\0')
    for(int j=1;j<=n;j++){
      if(c[i][j]=='0'&&!vis[i][j])
        {puts("NO");return;}
      d[i][j]=vis[i][j]?'1':'0';
    }
  puts("YES");
  for(int i=1;i<=n;i++)
    printf("%s\n",d[i]+1);
}
int main(){
  // freopen("in.txt","r",stdin);
  scanf("%d",&T);
  while(T--)solve();
}