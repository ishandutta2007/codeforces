#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 10000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int N,M,P,rnd;
int speed[1010], done;
int visited[1010][1010];
int ans[10];
queue<pi> Q[10];
string S;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>N>>M>>P;
  int TOT = N*M;
  for (int i=0;i<P;++i)cin>>speed[i];
  memset(visited,-1,sizeof(visited));
  for (int i=0;i<N;++i){
    cin>>S;
    for (int j=0;j<M;++j){
      if (S[j] == '#'){visited[i][j] = -2;--TOT;continue;}
      if (S[j] == '.')continue;
      int x = S[j] - '1';
      Q[x].push(mp(i,j));
      ++ans[x];
      ++done;
      visited[i][j] = 0;
    }
  }
  // done = P;
  int p = 0;
  while(done < TOT){
    if (done == p)break;
    p = done;
    ++rnd;
    for (int i=0;i<P;++i){
       while(Q[i].size()){
         pi cur = Q[i].front();
         if (visited[cur.f][cur.s] >= rnd * speed[i])break;
        //  cout<<i<<" visiting " << cur.f<<' '<<cur.s<<'\n';
         Q[i].pop();
         for (int k=0;k<4;++k){
           int x = cur.f + dx[k];
           int y = cur.s + dy[k];
           if (x<0||y<0||x>=N||y>=M)continue;
           if (visited[x][y] != -1)continue;
          //  cout<<i<<" visiting " << x<<' '<<y<<'\n';
           visited[x][y] = visited[cur.f][cur.s]+1;
           ++ans[i];
           ++done;
           Q[i].push(mp(x,y));
         }
       }
    }
  }
  for (int i=0;i<P;++i)cout<<ans[i]<<' ';
}