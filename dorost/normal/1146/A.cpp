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
   string s;
   cin>>s;
   int b=0,c=0;
   for(int i=0;i<s.size();i++){
     if(s[i]=='a'){
       b++;
     }else{
       c++;
     }
   }
   if(b>c){
     cout<<b+c;
   }else{
     cout<<b+b-1;
   }
 }