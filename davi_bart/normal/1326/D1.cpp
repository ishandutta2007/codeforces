#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
      string a;
      string sol="";
      cin>>a;
      if(a.size()==1){
        cout<<a<<'\n';
        continue;
      }
      int p=-1;
      for(int i=0;i<a.size()/2;i++){
        p=i;
        if(a[i]==a[a.size()-i-1]){
          sol.push_back(a[i]);
        }else{
          p--;
          break;
        }
      }
      string b="";
      for(int i=p+1;i<a.size()-p-1;i++)b.push_back(a[i]);
      if(b.size()>0){
        a="";
        for(int i=0;i<b.size();i++){
          a.push_back('.');
          a.push_back(b[i]);
        }
        a.push_back('.');
        vector<int> sub(a.size()+100,0);
        int N=a.size();
        int center = 0, last = 0;
        for(int i=1;i<N;i++){
          if(last > i)sub[i] = min(sub[center-(i-center)],last-i);
          while(i+sub[i]+1 < N && i-sub[i]-1 >= 0 && a[i+sub[i]+1]==a[i-sub[i]-1])sub[i]++;
          if(i+sub[i] > last){
              last = i+sub[i];
              center = i;
          }
        }
        int ma=-1;
        int pos;
        for(int i=0;i<N;i++){
            if(sub[i]>ma && (i==sub[i] || (sub[i]+i+1)==N)){
              ma=sub[i];
              pos=i;
            }
        }
        for(int i=pos-sub[pos];i<=pos+sub[pos];i++){
          if(a[i]!='.')sol.push_back(a[i]);
        }
      }
      for(int i=p;i>=0;i--)sol.push_back(sol[i]);
      cout<<sol<<'\n';
    }
    return 0;
}