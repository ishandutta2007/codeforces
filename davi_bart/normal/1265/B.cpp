#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
      int N;
      cin>>N;
      vector<pair<int,int> >v;
      for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back({a,i});
      }
      sort(v.begin(),v.end());
      int l=v[0].second,r=v[0].second;
      for(int i=0;i<N;i++){
        l=min(l,v[i].second);
        r=max(r,v[i].second);
        if(r-l==i)cout<<1;
        else cout<<0;
      }
      cout<<'\n';
		}
}