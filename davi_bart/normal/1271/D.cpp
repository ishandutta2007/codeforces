#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>a,b,c;
int v[6000];
vector<int>p[6000];
int memo[5500][5500];
int sol(int pos,int sold){
  if(pos==a.size())return 0;
  if(sold<a[pos])return -1000000000;
  if(memo[pos][sold]!=0)return memo[pos][sold];
  int s=sold;
  s+=b[pos];
  int ma=sol(pos+1,s);
  int tot=0;
  for(int i=0;i<p[pos].size();i++){
    s--;
    tot+=p[pos][i];
    ma=max(ma,sol(pos+1,s)+tot);
  }
  return memo[pos][sold]=ma;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
      int aa,bb,cc;
      cin>>aa>>bb>>cc;
      a.push_back(aa);b.push_back(bb);c.push_back(cc);
    }
    for(int i=0;i<5500;i++)v[i]=i;
    for(int i=0;i<M;i++){
      int u,l;
      cin>>u>>l;
      u--;
      l--;
      v[l]=max(v[l],u);
    }
    for(int i=0;i<N;i++){
      p[v[i]].push_back(c[i]);
    }
    for(int i=0;i<N;i++){
        sort(p[i].begin(),p[i].end(),greater<int>());
    }
    int t=sol(0,K);
    if(t<0)cout<< -1;
    else cout<<t;
    return 0;
}