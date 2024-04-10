#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n,k;
    cin>>n>>k;
    unsigned a=0,b=0;
    unsigned i;
    for(i=1;i<=n;++i){
        unsigned c;
        cin>>c;
        a+=c;
        unsigned trf=min(8u,a);
        a-=trf;
        b+=trf;
        if(b>=k)break;
    }
    if(i<=n){
        cout<<i<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}