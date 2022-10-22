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
    int T;
    cin>>T;
    for(int o=0;o<T;o++){
      int N;
      cin>>N;
      string s;
      cin>>s;
      int a=0,b=0;
      for(int i=0;i<N;i++){
        if(s[i]=='>')break;
        a++;
      }
      for(int i=N-1;i>=0;i--){
        if(s[i]=='<')break;
        b++;
      }
      cout<<min(a,b)<<endl;

    }
  return 0;
}