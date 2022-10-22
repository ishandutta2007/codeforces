#pragma GCC compiler("O3")
#include <bits/stdc++.h>
using namespace std;
int stringa[55];
int trova[4]={'A'-'A','C'-'A','T'-'A','G'-'A'};
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int N;
    cin>>N;
    string a;
    cin>>a;
    for(int i=0;i<N;i++){
      stringa[i]=a[i]-'A';
    }
    int mi=100000;
    for(int i=0;i<N-3;i++){
      int tot=0;
      tot+=min(abs(stringa[i]-trova[0]),26-abs(stringa[i]-trova[0]));
      tot+=min(abs(stringa[i+1]-trova[1]),26-abs(stringa[i+1]-trova[1]));
      tot+=min(abs(stringa[i+2]-trova[2]),26-abs(stringa[i+2]-trova[2]));
      tot+=min(abs(stringa[i+3]-trova[3]),26-abs(stringa[i+3]-trova[3]));
      if(tot<mi)mi=tot;
    }
    cout<<mi;
    return 0;
}