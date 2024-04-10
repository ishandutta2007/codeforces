#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int par[200010],dim[200010];
int parent(int a){
  if(a==par[a])return a;
  return par[a]=parent(par[a]);
}
void unisci(int a,int b){
  if(dim[a]>dim[b])swap(a,b);
  par[a]=b;
  dim[b]+=dim[a];
}
vector<pair<pair<int,int>,int> > v;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,M;
		cin>>N>>M;
		iota(par,par+N+2,0);
		for(int i=0;i<M;i++){
      int a,b,c;
      cin>>a>>b>>c;
      v.push_back({{c,a},b});
		}
		sort(v.begin(),v.end());
		v.push_back({{2000000000,0},0});
		vector<int> l;
		int tot=0;
		for(int i=0;i<v.size();i++){
      if(l.size() && v[i].first.first>v[l[0]].first.first){
        for(int j=0;j<l.size();j++){
          int a=v[l[j]].first.second,b=v[l[j]].second;
          if(parent(a)==parent(b)){
            tot++;
            continue;
          }
          unisci(parent(a),parent(b));
        }
        l.clear();
      }
      int a=v[i].first.second,b=v[i].second;
      if(parent(a)==parent(b))continue;
      l.push_back(i);
		}
		cout<<tot<<endl;
    return 0;
}