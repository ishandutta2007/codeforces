#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      string a;
      cin>>a;
      sort(a.begin(),a.end());
      int tot=0;
      bool l=0;
      int p=0;
      for(int j=0;j<a.size();j++){
        int u=a[j]-'0';
        tot+=u;
        if(u%2==0)p++;
        if(u==0)l=1;
      }
      if(tot%3==0 && p>1 && l)cout<<"red"<<endl;
      else cout<<"cyan"<<endl;
    }
    return 0;
}