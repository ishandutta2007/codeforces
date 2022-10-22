#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
char c[1000000];
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>c[i];
  }
  int tot=0;
  for(int i=1;i<N;i++){
    if(c[i]==c[i-1]){
      tot++;
      if(c[i-1]!='R' && c[i+1]!='R'){
        c[i]='R';
        continue;
      }
      if(c[i-1]!='G' && c[i+1]!='G'){
        c[i]='G';
        continue;
      }
      if(c[i-1]!='B' && c[i+1]!='B'){
        c[i]='B';
        continue;
      }
    }
  }
  cout<<tot<<endl;
  for(int i=0;i<N;i++){
    cout<<c[i];
  }
  return 0;
}