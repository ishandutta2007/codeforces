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
      vector<int> p;
      for(int i=0;i<N;i++){
        int a;
        cin>>a;
        p.push_back(a);
      }
      int prec=p.back();
      while(p.size() && (p.size()>N/2 || p.back()==prec)){
        p.pop_back();
        if(p.size()>N/2)prec=p.back();
      }
      if(p.size()<3){
        cout<<"0 0 0"<<endl;
        continue;
      }
      vector<int> v;
      v.push_back(1);
      prec=p[0];
      for(int i=1;i<p.size();i++){
        if(p[i]==prec)v.back()++;
        else{
          v.push_back(1);
          prec=p[i];
        }
      }
      int tot=p.size();
      int k=v[0];
      bool j=0;
      for(int i=1;i<v.size();i++){
        k-=v[i];
        if(k<0){
          if(v[0]<tot-v[0]-v[0]+k){
            cout<<v[0]<<" "<<v[0]-k<<" "<<tot-v[0]-v[0]+k<<endl;
            j=1;
            break;
          }else{
            cout<<"0 0 0"<<endl;
            j=1;
            break;
          }
        }
      }
      if(!j)cout<<"0 0 0"<<endl;
    }
		return 0;
}