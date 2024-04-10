#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n,m,a;
    cin>>n>>m>>a;
    cout<<static_cast<unsigned long long>((n+a-1)/a)*((m+a-1)/a)<<endl;
}