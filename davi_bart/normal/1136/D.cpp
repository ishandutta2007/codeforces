#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> v[300010];
vector<int> p;
vector<int> rim;
bool controlla(int val){
  for(int i=0;i<rim.size();i++){
    if(v[val].find(rim[i])==v[val].end())return 0;
  }
  return 1;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,M;
		cin>>N>>M;
		for(int i=0;i<N;i++){
      int a;
      cin>>a;
      p.push_back(a);
		}
		reverse(p.begin(),p.end());
		for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      v[a].insert(b);
		}
		int io=p[0];
		for(int i=1;i<p.size();i++){
      int k=p[i];
      if(v[k].find(io)!=v[k].end() && controlla(k))continue;
      rim.push_back(k);
		}
		cout<<N-rim.size()-1;
		return 0;
}