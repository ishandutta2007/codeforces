#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int v[20][100010];
vector<pair<int,bool> > p[100010];
vector<pair<int,int> > x;
int minimo(int a,int b){
  if(b<a)return 1000000000;
  int l=31-__builtin_clz(b-a+1);
  return min(v[l][a],v[l][b-(1<<l)+1]);
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,M;
		cin>>N>>M;
		for(int i=0;i<N;i++){
      cin>>v[0][i];
		}
		for(int i=1;(1<<i)<=N;i++){
      for(int j=0;(j+(1<<(i)))<=N;j++){
        v[i][j]=min(v[i-1][j],v[i-1][j+(1<<(i-1))]);
      }
		}
		for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      x.push_back({a,b});
      for(int j=0;j<a;j++){
        p[j].push_back({a,0});
        p[j].push_back({b,1});
      }
      for(int j=b+1;j<N;j++){
        p[j].push_back({a,0});
        p[j].push_back({b,1});
      }
		}
		for(int i=0;i<N;i++)sort(p[i].begin(),p[i].end());
		int best=0,pos;
		for(int i=0;i<N;i++){
      int mi=min(minimo(0,i-1),minimo(i+1,N-1));
      int t=1,prec;
      for(int j=0;j<p[i].size();j++){
        if(j==0){prec=p[i][j].first;continue;}
        if(p[i][j].second==0){
          mi=min(mi,minimo(prec,p[i][j].first-1)-t);
          t++;
          prec=p[i][j].first;
        }else{
          mi=min(mi,minimo(prec,p[i][j].first)-t);
          t--;
          prec=p[i][j].first;
        }
      }
      if(v[0][i]-mi>best){
        best=v[0][i]-mi;
        pos=i;
      }
		}
		int o=0;
		for(int i=0;i<M;i++){
      if(x[i].first>pos || x[i].second<pos)o++;
		}
		cout<<best<<endl<<o<<endl;
		for(int i=0;i<M;i++){
      if(x[i].first>pos || x[i].second<pos)cout<<i+1<<" ";
		}
    return 0;
}