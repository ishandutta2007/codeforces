#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
      string a;
      cin>>a;
      int p=1000,l=0,k=0;
      for(int i=0;i<a.size();i++){
        k+=a[i]-'0';
        if(a[i]=='1'){
          p=min(p,i);
          l=i;
        }
      }
      if(k==0)cout<<0<<'\n';
      else cout<<l-p+1-k<<'\n';
		}

    return 0;
}