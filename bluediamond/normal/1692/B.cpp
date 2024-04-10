#include <bits/stdc++.h>


using namespace std;
int v[10001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //freopen ("___input___.txt","r",stdin);

  int t,cnt=0;
  cin>>t;
  for (int q=1; q<=t; q++) {
    for (int i=1; i<=10000; i++) {
      v[i]=0;
    }
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {

      int x;
      cin>>x;
      v[x]++;
    }
    sort (v+1,v+10000+1);
    reverse(v+1,v+10000+1);
    n=0;
    for (int i=1; i<=10000; i++) {
      if (v[i]!=0) {
        n++;
      }
    }
    while (1) {
      bool schimbare=0;
      for (int i=1; i<=n; i++) {
        if (v[i]>=2) {
          bool gasit_pereche=0;
          for (int j=1;j<=n;j++){
            if(v[j]>=2&&i!=j){
              v[i]--;
              v[j]--;
              gasit_pereche=1;
              break;
            }
          }
          if(gasit_pereche==0){
            v[i]-=2;
          }
          schimbare=1;
        }
      }

      if(schimbare==0){
        break;
      }
    }
    int s=0;
    for(int i=1;i<=n;i++){
      s+=v[i];
    }
    cout<<s<<"\n";
  }




  return 0;
}