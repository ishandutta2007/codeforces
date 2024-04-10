#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=0;i<4;i++){
      int a1=a,b1=b,c1=c,d1=d;
      vector<int> v;
      if(a>0 && i==0){
        v.push_back(0);
        a1--;
      }else if(d>0 && i==3){
        v.push_back(3);
        d1--;
      }else if(b>0 && i==1){
        v.push_back(1);
        b1--;
      }else if(c>0 && i==2){
        v.push_back(2);
        c1--;
      }else continue;
      bool ok=0;
      for(;a1+b1+c1+d1>0;){
        if(i==0 || i==1){
          if(a1>0 && v.back()!=0 && abs(v.back()-0)==1){
            v.push_back(0);
            a1--;
          }else if(b1>0 && v.back()!=1&& abs(v.back()-1)==1){
            v.push_back(1);
            b1--;
          }else if(c1>0 && v.back()!=2&& abs(v.back()-2)==1){
            v.push_back(2);
            c1--;
          }else if(d1>0 && v.back()!=3&& abs(v.back()-3)==1){
            v.push_back(3);
            d1--;
          }else{
            ok=1;
            break;
          }
        }else{
          if(d1>0 && v.back()!=3&& abs(v.back()-3)==1){
            v.push_back(3);
            d1--;
          }else if(c1>0 && v.back()!=2&& abs(v.back()-2)==1){
            v.push_back(2);
            c1--;
          }else if(b1>0 && v.back()!=1&& abs(v.back()-1)==1){
            v.push_back(1);
            b1--;
          }else if(a1>0 && v.back()!=0&& abs(v.back()-0)==1){
            v.push_back(0);
            a1--;
          }else{
            ok=1;
            break;
          }
        }
      }
      if(ok==0){
        cout<<"YES"<<endl;
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        return 0;
      }
    }
  cout<<"NO";

		return 0;
}