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
  int a,b;
  cin>>a>>b;
  cout<<min(a,b);
  cout<<" "<<((a+b)-(2*(min(a,b))))/2;
}