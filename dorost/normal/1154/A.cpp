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
  int a,b,c,d,e;
  cin>>a>>b>>c>>d;
  e=max({a, b, c, d});
  if(e==a){
    cout<<e-b<<" ";
    cout<<e-c<<" ";
    cout<<e-d;
  }
  if(e==b){
    cout<<e-a<<" ";
    cout<<e-c<<" ";
    cout<<e-d;
  }
  if(e==c){
    cout<<e-b<<" ";
    cout<<e-a<<" ";
    cout<<e-d;
  }
  if(e==d){
    cout<<e-b<<" ";
    cout<<e-c<<" ";
    cout<<e-a;
  }
}