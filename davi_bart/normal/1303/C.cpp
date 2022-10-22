#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
string sol;
vector<int> v[30];
bool vis[30];
void dfs(int pos){
  if(vis[pos])return;
  vis[pos]=1;
  sol.push_back((char)pos+'a');
  for(int i=0;i<v[pos].size();i++)dfs(v[pos][i]);
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll T;
		cin>>T;
		while(T--){
      sol="";
      fill(vis,vis+29,0);
      for(int i=0;i<29;i++)while(v[i].size())v[i].pop_back();
      string a;
      cin>>a;
      for(int i=0;i<a.size()-1;i++){
        v[a[i]-'a'].push_back(a[i+1]-'a');
        v[a[i+1]-'a'].push_back(a[i]-'a');
      }
      for(int i=0;i<26;i++){
        sort(v[i].begin(),v[i].end());
        v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin());
      }
      bool perso=0;
      for(int i=0;i<26;i++){
        if(v[i].size()>2)perso=1;
      }
      if(perso){
        cout<<"NO"<<'\n';
        continue;
      }
      while(1){
        int primo=-1;
        for(int i=0;i<26;i++){
          if(!vis[i] && v[i].size()==1)primo=i;
        }
        if(primo==-1){
          for(int i=0;i<26;i++){
            if(!vis[i] && v[i].size()==0)sol.push_back((char)i+'a');
          }
          break;
        }
        dfs(primo);
      }
      if(sol.size()<26){
        cout<<"NO"<<'\n';
        continue;
      }
      cout<<"YES"<<'\n';
      cout<<sol<<'\n';
		}
    return 0;
}