#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n,k;
    cin>>n>>k;
    cout<<((k==0||k==n)?0u:1u)<<' '<<((3*k<=n)?(2*k):(n-k))<<endl;
}