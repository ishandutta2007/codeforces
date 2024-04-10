#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int> > v,p;
vector<pair<pair<int,int>,int> > q;
vector<int> sol(200010);
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
          sol[q[pos].second]=p[q[pos].first.second-1].first;
          pos++;
      }
      p.push_back(v[i]);
      int h=i;
      while(h>0 && p[h].second<p[h-1].second){
        swap(p[h],p[h-1]);
        h--;
      }
    }
    for(int i=0;i<M;i++)cout<<sol[i]<<'\n';
		return 0;
}