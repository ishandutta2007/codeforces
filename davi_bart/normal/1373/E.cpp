#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string mix(string a,string b){
  if(a.size()<b.size())return a;
  if(a.size()>b.size())return b;
  for(int i=0;i<a.size();i++){
    if(a[i]==b[i])continue;
    if(a[i]<b[i])return a;
    return b;
  }
  return a;
}
void solve(){
  int N,K;
  cin>>N>>K;
  K++;
  string mi(100,'9');
  string q=mi;
  for(int i=0;i<20;i++){
    for(int j=0;j<10;j++){
      int s=0;
      int cur=i*9;
      for(int h=0;h<K;h++){
        if(h+j!=10){
          s+=cur+(j+h)%10;
        }else{
          cur=1;
          s+=cur+(j+h)%10;
        }
      }
      if(s<=N && (N-s)%K==0){
          //cout<<"ok"<<endl;
        string x="";
        int a=(N-s)/K;
        //if(N==99)cout<<a<<endl;
        if(a>=8){
            x="8";
            a-=8;
        }
        while(a>9){
            x+='9';
            a-=9;
        }
        if(a)x+=to_string(a);
        reverse(x.begin(),x.end());
        for(int w=0;w<i;w++)x+='9';
        x+=to_string(j);
        mi=mix(mi,x);
      }
    }
  }
  if(q==mi)cout<<-1<<'\n';
  else cout<<mi<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}