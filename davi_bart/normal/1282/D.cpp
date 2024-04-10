#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<"a"<<endl;
    int N;
    cin>>N;
    if(N==0)return 0;
    if(N==300){
      for(int i=0;i<N;i++)cout<<'b';
      cout<<endl;
      return 0;
    }
    N++;
    string sol="";
    for(int i=0;i<N;i++){
      sol+="a";
    }
    cout<<sol<<endl;
    int p;
    cin>>p;
    if(p==0)return 0;
    if(p==N){
      for(int i=0;i<N;i++)sol[i]='b';
      sol.pop_back();
      cout<<sol<<endl;
      int o;
      cin>>o;
      if(o==0)return 0;
      sol.push_back('b');
      cout<<sol<<endl;
      cin>>o;
      return 0;
    }
    for(int i=0;i<N;i++){
      sol[i]='b';
      cout<<sol<<endl;
      int k;
      cin>>k;
      if(k==0)return 0;
      if(k>p){
          sol[i]='a';
          continue;
      }
      p=k;
    }
    return 0;
}