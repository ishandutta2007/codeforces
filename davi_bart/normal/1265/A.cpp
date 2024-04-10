#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
      string a;
      cin>>a;
      a+='d';
      bool p=0;
      for(int i=1;i<a.size()-1;i++){
        if(a[i]==a[i-1] && a[i]!='?'){
          cout<<-1<<endl;
          p=1;
          break;
        }
        if(a[i]=='?'){
          if(a[i-1]!='a' && a[i+1]!='a')a[i]='a';
          else if(a[i-1]!='b' && a[i+1]!='b')a[i]='b';
          else if(a[i-1]!='c' && a[i+1]!='c')a[i]='c';
          else {
            cout<<-1<<endl;
          p=1;
          break;
          }
        }
      }
      if(a[0]=='?'){
        if(a[1]!='a')a[0]='a';
        else a[0]='c';
      }
      a.pop_back();
      if(p)continue;
      cout<<a<<endl;
		}
}