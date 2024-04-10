#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
vector<pair<int,int> > v;
vector<pair<pair<int,int>,int> > q;
vector<int> sol(200010);
ordered_set p;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      v.push_back({a,i});
    }
    sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
         if(a.first==b.first)return a.second<b.second;
         return a.first>b.first;
    });
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      q.push_back({{a,b},i});
    }
    sort(q.begin(),q.end());
    int pos=0;
    for(int i=0;i<=N;i++){
      while(i==q[pos].first.first){
          sol[q[pos].second]=(*p.find_by_order(q[pos].first.second-1)).second;
          pos++;
      }
      p.insert({v[i].second,v[i].first});
    }
    for(int i=0;i<M;i++)cout<<sol[i]<<'\n';
		return 0;
}