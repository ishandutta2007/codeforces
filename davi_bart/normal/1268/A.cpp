#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v,p;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K;
    cin>>N>>K;
    v.resize(N);p.resize(N);
    for(int i=0;i<N;i++){
      char a;
      cin>>a;
      v[i]=a-'0';
    }
    for(int i=0;i<N;i++)p[i]=v[i%K];
    bool m=0;
    for(int i=K;i<N;i++){
      if(p[i]>v[i])break;
      if(p[i]<v[i]){
        m=1;
        break;
      }
    }
    if(m)p[K-1]++;
    int pos=K;
    p.insert(p.begin(),0);
    while(p[pos]>=10){
      p[pos]=p[pos]%10;
      p[pos-1]++;
      pos--;
    }
    if(p[0]>0){
      cout<<p.size()<<endl;
      for(int i=0;i<p.size();i++){
        if(i>K)cout<<p[i%K];
        else cout<<p[i];
      }
      return 0;
    }
    p.erase(p.begin());
    cout<<p.size()<<endl;
    for(int i=0;i<p.size();i++){
      cout<<p[i%K];
    }
    return 0;
}