#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int a=0,n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    if(s[0] == 'T'){
      a = a + 4;
    }
    if(s[0] == 'C'){
      a = a + 6;
    }
    if(s[0] == 'O'){
      a=a+8;
    }
    if(s[0] == 'D'){
      a=a+12;
    }
    if(s[0] == 'I'){
      a=a+20;
    }
    // cout << a << endl;
  }
  cout<<a;
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