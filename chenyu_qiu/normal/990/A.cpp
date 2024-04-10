#include <iostream>
#include <queue>
using namespace std;
 
int main() {
    long long n,m,a,b;
    cin>>n>>m>>a>>b;
    if(n%m==0) cout<<0<<endl;
    else{
        long long x = n%m;
        cout<<min(b*x,(m-x)*a)<<endl;
    }
    return 0;
}