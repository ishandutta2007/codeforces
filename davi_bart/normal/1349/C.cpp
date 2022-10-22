#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll N,M,Q;
bool v[1009][1009];
ll tempo[1009][1009];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		for(ll i=0;i<1005;i++){
      for(ll j=0;j<1005;j++)tempo[i][j]=-1;
		}
		cin>>N>>M>>Q;
		for(ll i=0;i<N;i++){
      string a;
      cin>>a;
      for(ll j=0;j<M;j++){
        v[i][j]=a[j]-'0';
      }
		}
		queue<pair<pair<ll,ll>,ll> >q;
		for(ll i=0;i<N;i++){
      for(ll j=0;j<M;j++){
        if(i<(N-1) && v[i][j]==v[i+1][j]){
          q.push({{i,j},1});
          q.push({{i+1,j},1});
        }
        if(j<(M-1) && v[i][j]==v[i][j+1]){
          q.push({{i,j},1});
          q.push({{i,j+1},1});
        }
      }
		}
		while(!q.empty()){
      ll y=q.front().first.first;
      ll x=q.front().first.second;
      ll t=q.front().second;
      q.pop();
      if(tempo[y][x]!=-1)continue;
      tempo[y][x]=t;
      bool k=!v[y][x];
      if(y>0 && v[y-1][x]==k)q.push({{y-1,x},t+1});
      if(y<(N-1) && v[y+1][x]==k)q.push({{y+1,x},t+1});
      if(x>0 && v[y][x-1]==k)q.push({{y,x-1},t+1});
      if(x<(M-1) && v[y][x+1]==k)q.push({{y,x+1},t+1});
		}
		/*cout<<"tempo"<<endl;
		for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cout<<tempo[i][j]<<" ";
      }
      cout<<endl;
		}
		cout<<endl;*/
		for(ll i=0;i<Q;i++){
      ll a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      if(tempo[a][b]==-1 || c<tempo[a][b]){
        cout<<v[a][b]<<'\n';
        continue;
      }
      bool k=v[a][b];
      if((c-tempo[a][b])%2==0)k=!k;
      cout<<k<<'\n';
		}
		//long long !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
    return 0;
}