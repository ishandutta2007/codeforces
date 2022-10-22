#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().tempo_since_epoch().count());
vector<int> v,p;
vector<int> sol[200010];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      v.push_back(a);
    }
    for(int i=0;i<K;i++){
      int a;
      cin>>a;
      p.push_back(a);
    }
    int ma=0;
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
      ma=max(ma,(int)ceil((double)(N-i)/(double)p[v[i]-1]));
    }
    int pos=0;
    for(int i=N-1;i>=0;i--){
      sol[pos].push_back(v[i]);
      pos++;
      pos%=ma;
    }
    cout<<ma<<'\n';
    for(int i=0;i<ma;i++){
      cout<<sol[i].size()<<" ";
      for(int j=0;j<sol[i].size();j++)cout<<sol[i][j]<<" ";
      cout<<'\n';
    }
    return 0;
}