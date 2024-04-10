#include <iostream>
using namespace std;
unsigned gcd(unsigned a, unsigned b){
    while(a>0){
        unsigned c=b%a;
        b=a;
        a=c;
    }
    return b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n;
    cin>>n;
    for(unsigned i=(n-1)>>1;i>0;--i){
        if(gcd(i,n-i)==1){
            cout<<i<<' '<<n-i<<endl;
            return 0;
        }
    }
}