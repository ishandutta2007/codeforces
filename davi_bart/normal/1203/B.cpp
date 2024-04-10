#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
      int N;
      cin>>N;
      vector<int> p;
      for(int i=0;i<4*N;i++){
        int a;
        cin>>a;
        p.push_back(a);
      }
      sort(p.begin(),p.end());
      int tot=p[0]*p[4*N-1];
      bool perso=0;
      for(int i=0;i<2*N;i+=2){
        if(p[i]==p[i+1] && p[4*N-i-1]==p[4*N-i-2] && p[i]*p[4*N-i-1]==tot)continue;
        perso=1;
        break;
      }
      if(perso)cout<<"NO"<<'\n';
      else cout<<"YES"<<'\n';
		}
		return 0;
}