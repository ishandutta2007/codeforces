#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N;
int inf=1e18;
struct node{
  int a,b,c,pos;
};
vector<node> p(200010);
vector<node> w;
vector<int> v[200010];
pair<int,int> k[200010];
bool vis[200010];
int par[200010];
pair<int,int> dfs(int pos,int prec){
  par[pos]=prec;
  int a=0,b=0;
  for(int i=0;i<v[pos].size();i++){
    if(v[pos][i]==prec)continue;
    auto n=dfs(v[pos][i],pos);
    a+=n.first;
    b+=n.second;
  }
  if(p[pos].b==0 && p[pos].c==1)a++;
  if(p[pos].b==1 && p[pos].c==0)b++;
  return k[pos]={a,b};
}
pair<int,int> sol(int pos,int prec){
  if(vis[pos])return k[pos];
  vis[pos]=1;
  int a=0,b=0;
  if(w[pos].b==0 && w[pos].c==1)a++;
  if(w[pos].b==1 && w[pos].c==0)b++;
  for(int i=0;i<v[pos].size();i++){
    if(v[pos][i]==prec)continue;
    auto n=sol(v[pos][i],pos);
    a+=n.first;
    b+=n.second;
  }
  return k[pos]={a,b};
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
		int N;
		cin>>N;
		p.resize(N);
		int tt=0;
		for(int i=0;i<N;i++){
      int a,b,c;
      cin>>a>>b>>c;
      tt+=b-c;
      p[i]={a,b,c,i};
		}
		for(int i=0;i<N-1;i++){
      int a,b;
      cin>>a>>b;
      v[a-1].push_back(b-1);
      v[b-1].push_back(a-1);
		}
		if(tt!=0){
      cout<<-1;
      return 0;
		}
		for(int i=0;i<p.size();i++)w.push_back(p[i]);
		sort(p.begin(),p.end(),[](node a,node b){
       return a.a<b.a;
    });
		dfs(0,-1);
		int tot=0;
		for(int i=0;i<N;i++){
      int pos=p[i].pos;
      if(vis[pos])continue;
      sol(pos,par[pos]);
      int x=min(k[pos].first,k[pos].second);
      tot+=p[i].a*x*2;
      k[pos].first-=x;
      k[pos].second-=x;
		}
		cout<<tot;
}