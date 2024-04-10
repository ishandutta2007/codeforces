//        aa                                                  ii
//       aaaa
//      aa  aa             mm  mmmmmmmmm   mmmmmmmmm          ii     rr  rr    rr  rr         eeeeeeee    zzzzzzzzzzz          aaaa
//     aa    aa            mm m         m m         m         ii     rr r      rr r         ee        ee          zz         aa     aa
//    aaaaaaaaaa           mmm           m            m       ii     rrr       rrr          eeeeeeeeeeeee       zz         aa        aa
//   aa        aa          mm            m            m       ii     rr        rr           ee               zz           aa         aa
//  aa          aa         mm            m            m       ii     rr        rr            ee            zz              aa      aa  aa
// aa            aa        mm            m            m       ii     rr        rr             eeeeeee     zzzzzzzzzz          aaaa      aa
//aa              aa       mm            m            m       ii     rr        rr
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int a=0,d=0,n;
  cin>>n;
  cin>>s;
  for(int i = 0;i < s.size();i++){
    if(s[i]=='A'){
      a++;
    }
    if(s[i]=='D'){
      d++;
    }
  }
  if(d > a){
    cout<<"Danik";
  }else if(a>d){
    cout<<"Anton";
  }else{
    cout<<"Friendship";
  }
}