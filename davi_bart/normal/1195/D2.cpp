#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
int N;
int cifre[20];
vector<string> v;
ll pot[30];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    pot[0]=1;
    for(int i=1;i<30;i++){
      pot[i]=pot[i-1]*10;
      pot[i]%=mod;
    }
    cin>>N;
    for(int i=0;i<N;i++){
      string p;
      cin>>p;
      cifre[p.size()+1]++;
      reverse(p.begin(),p.end());
      v.push_back(p);
    }
    for(int i=2;i<20;i++){
      cifre[i]+=cifre[i-1];
    }
    ll tot=0;
    for(int i=0;i<v.size();i++){
      for(int j=0;j<v[i].size();j++){
        ll o=v[i][j]-'0';
        ll pos=j*2;
        ll manc=N;
        int h=j;
        while(manc>0){
          ll volte=manc-cifre[h];
          manc=cifre[h];
          tot+=o*volte*pot[pos];
          tot%=mod;
          pos--;
          h--;
        }
        manc=N;
        h=j;
        pos=j*2+1;
        while(manc>0){
          ll volte=manc-cifre[h+1];
          manc=cifre[h+1];
          tot+=o*volte*pot[pos];
          tot%=mod;
          pos--;
          h--;
        }
      }
    }
    cout<<tot;
    return 0;
}