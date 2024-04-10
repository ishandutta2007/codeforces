#include<iostream>
using namespace std;
int main(){
long long hb, hr, wb, wr, c, ans =0;
cin>>c>>hr>>hb>>wr>>wb;
for(long long i=0; i<100000;i++){
if(i*wr<=c){
ans =max(ans, i*hr+ (c-wr*i)/wb * hb);}
if(i*wb<=c){
ans =max(ans, i*hb+ (c-wb*i)/wr * hr);}
}
cout<<ans;
return 0;
}