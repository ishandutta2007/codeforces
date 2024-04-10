#include <iostream>
#include <algorithm>
using namespace std;
unsigned n;
char c='a';
unsigned find_msc(unsigned& n){
    unsigned clf=0;
    unsigned i;
    for(i=1;clf+i<=n;++i){
        clf+=i;
    }
    n-=clf;
    return i;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    if(n==0){
        cout<<'z'<<endl;
        return 0;
    }
    while(n>0){
        unsigned ret=find_msc(n);
        for(unsigned i=0;i<ret;++i){
            cout<<c;
        }
        ++c;
    }
    cout<<endl;
}