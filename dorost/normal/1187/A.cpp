#include <bits/stdc++.h>
using namespace std;

int main(){
  int t,a,b,c;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>a>>b>>c;
    if(b<c){
      cout<<(a-b)+1<<endl;
    }else{
      cout<<(a-c)+1<<endl;
    }
  }
}
//
//           aa
//          aa aa
//         aa   aa
//        aa     aa
//       aaaaaaaaaaa
//      aa         aa
//     aa           aa
//    aa             aa
//   aa               aa