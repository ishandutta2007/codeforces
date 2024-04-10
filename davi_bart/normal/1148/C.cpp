#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<pair<int,int> >sol;
unordered_map<int,int> v;
int N,n;
void scambia(int i,int j){
  sol.push_back({i,j});
  v[a[j]]=i;
  v[a[i]]=j;
  swap(a[i],a[j]);

}
void s(int i,int j){
  if(i==j)return;
  if(i>j)swap(i,j);
  if(abs(i-j)>=n){
    scambia(i,j);
    return;
  }
  if(i<=n && j>n){
    scambia(i,N);
    scambia(1,N);
    scambia(1,j);
    scambia(1,N);
    scambia(i,N);
    return;
  }
  if(j<=n){
    scambia(j,N);
    scambia(i,N);
    scambia(j,N);
    return;
  }
  if(i>n){
    scambia(i,1);
    scambia(j,1);
    scambia(i,1);
    return;
  }
}
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin>>N;
    n=N/2;
    int o;
    a.push_back(0);
    for(int i=1;i<=N;i++){
      cin>>o;
      a.push_back(o);
      v[o]=i;
    }
    for(int i=1;i<=N;i++){
      s(v[i],i);
    }
    cout<<sol.size()<<endl;
    for(int i=0;i<sol.size();i++){
      cout<<sol[i].first<<" "<<sol[i].second<<endl;
    }
    return 0;
}