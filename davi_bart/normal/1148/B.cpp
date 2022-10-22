#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int N,M,t1,t2,K;
    cin>>N>>M>>t1>>t2>>K;
    int o;
    for(int i=0;i<N;i++){
      cin>>o;
      a.push_back(o+t1);
    }
    for(int i=0;i<M;i++){
      cin>>o;
      b.push_back(o);
    }
    if(K>=min(N,M)){
      cout<<-1;
      return 0;
    }
    for(int i=K;i>=0;i--){
      if(a[i]>b[M-(K-i)-1]){
        cout<<-1;
        return 0;
      }
    }
    int mi=0;
    for(int i=K;i>=0;i--){
      int p=lower_bound(b.begin(),b.end(),a[i])-b.begin();
      int dacanc=K-i;

      if(b[p+dacanc]>mi)mi=b[p+dacanc];
    }
    cout<<mi+t2;
    return 0;
}