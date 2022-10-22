#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    string a;
    cin>>a;
    for(int i=0;i<N-1;i++){
      if(a[i]>a[i+1]){
        cout<<"YES"<<endl;
        cout<<i+1<<" "<<i+2;
        return 0;
      }
    }
    cout<<"NO";
    return 0;
}