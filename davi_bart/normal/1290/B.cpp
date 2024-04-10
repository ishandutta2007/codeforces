#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<int> v[30];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string c;
    cin>>c;
    for(int i=0;i<c.size();i++){
      v[c[i]-'a'].push_back(i);
    }
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      if(a==b){
        cout<<"Yes"<<'\n';
        continue;
      }
      vector<int> k;
      for(int j=0;j<28;j++){
        int diff=upper_bound(v[j].begin(),v[j].end(),b)-upper_bound(v[j].begin(),v[j].end(),a-1);
        if(diff>0){
          k.push_back(diff);
          if(k.size()>=3)break;
        }
      }
      if(k.size()>=3){
        cout<<"Yes"<<'\n';
        continue;
      }
      if(k.size()==1){
        cout<<"No"<<'\n';
        continue;
      }
      if(c[a]==c[b]){
        cout<<"No"<<'\n';
        continue;
      }
      cout<<"Yes"<<'\n';
    }
    return 0;
}