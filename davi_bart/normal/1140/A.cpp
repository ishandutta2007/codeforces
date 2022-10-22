#pragma GCC optimize("O3")
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int a[10009];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
      cin>>a[i];
}
    int tot=0;
    for(int i=1;i<=N;i++){
      int ma=0;
      for(int j=i;j<=N;j++){
        if(a[j]>ma)ma=a[j];
        if(j==ma){
                i=j;
            break;
        }
      }
      tot++;
    }
    cout<<tot;
    return 0;
}