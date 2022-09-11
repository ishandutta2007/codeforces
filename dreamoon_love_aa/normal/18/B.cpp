#include<iostream>
using namespace std;
main(){
    int i;
    long long n,d,m,l,now=0;
    cin>>n>>d>>m>>l;
    for(i=0;i<m;i++){
        now+=d;
        if(now%m>l||now>m*(n-1)+l)break;
    }
    if(i<m)cout<<now<<endl;
    else{
        now=(m*(n-1)+l+d)/d*d;
        cout<<now<<endl;
    }
}