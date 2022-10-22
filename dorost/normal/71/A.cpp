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

int main(){
  string s,ss,sss;
  int a,t;
  cin>>t;
  for(int g=0;g<t;g++){
    cin>>s;
    a=s.size();
  for(int i=0;i<a;i++){
    if(i==a-1){
      ss=s[i];
    }
    if(i==0){
      sss=s[i];
    }
  }
  if(a<11){
    cout<<s<<endl;
  }else{
  cout<<sss;
  cout<<a-2;
  cout<<ss<<endl;
}
}
}