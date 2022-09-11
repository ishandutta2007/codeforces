#include<iostream>
#include<algorithm>
using namespace std;
long long f(){
}
main(){
    long long l,r,an=0,x,y,i;
    cin>>l>>r;
    if(r==1000000000)an=max(an,r*(8999999999ll));
    for(i=10;i<=1000000000;i*=10){
        y=i-1;
        x=i/10;
        x=max(x,l);
        y=min(y,r);
        if(x>y)continue;
        if(x<=i/2&&i/2<=y)an=max(an,i/2*(i-1-i/2));
        else{
            an=max(an,x*(i-1-x));
            an=max(an,y*(i-1-y));
        }
    }
    cout<<an<<endl;
}