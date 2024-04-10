#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int memo[5009][5009];
int sol(int a,int b){
  if(a==b)return 0;
  if(memo[a][b])return memo[a][b];
  if(v[a]==v[b])return memo[a][b]=sol(a+1,b-1)+1;
  return memo[a][b]=min(sol(a+1,b),sol(a,b-1))+1;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
      int a;
      cin>>a;
      if(i==0 || a!=v.back())v.push_back(a);
		}
		cout<<sol(0,v.size()-1);
    return 0;
}