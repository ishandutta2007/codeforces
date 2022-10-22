#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int v[450][450];
int vv[450][450];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll T;
		cin>>T;
		while(T--){
      string a,b;
      cin>>a>>b;
      for(int j=0;j<=b.size();j++){//k
          for(int h=0;h<=b.size();h++){//kk
            vv[j][h]=-1000000;
            v[j][h]=-1000000;
          }
      }
      for(int i=0;i<b.size();i++){
        vv[i][b.size()]=i;
      }
      for(int i=a.size()-1;i>=0;i--){
        for(int j=0;j<=b.size();j++){//k
          for(int h=0;h<=b.size();h++){//kk
            if(j<b.size() && b[j]==a[i])v[j][h]=max(v[j][h],vv[j+1][h]);
            if(h<b.size() && b[h]==a[i])v[j][h]=max(v[j][h],vv[j][h+1]);
            v[j][h]=max(v[j][h],vv[j][h]);
          }
        }
        for(int j=0;j<=b.size();j++){//k
          for(int h=0;h<=b.size();h++){//kk
            vv[j][h]=v[j][h];
            v[j][h]=-1000000;
          }
        }
      }
      bool p=0;
      for(int i=0;i<=b.size();i++){
        if(vv[0][i]>=i)p=1;
      }
      if(p)cout<<"YES"<<'\n';
      else cout<<"NO"<<'\n';
		}
    return 0;
}