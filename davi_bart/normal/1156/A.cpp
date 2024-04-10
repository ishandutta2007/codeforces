#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    cin>>a[0];
    int tot=0;
    for(int i=1;i<N;i++){
      cin>>a[i];
      if((a[i]==2 && a[i-1]==3)||(a[i]==3 && a[i-1]==2)){
        cout<<"Infinite";
        return 0;
      }
      if(a[i]==2 || a[i-1]==2)tot+=3;
      else tot+=4;
    }
    for(int i=2;i<N;i++){
      if(a[i]==2 && a[i-1]==1 && a[i-2]==3)tot--;
    }
    cout<<"Finite"<<endl;
    cout<<tot;

    return 0;
}