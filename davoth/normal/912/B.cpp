#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    long long c=1;
    for(int i=0;;i++){
        c*=2;
        if(c>n){
            cout<<c-1;
            return 0;
        }
    }
    return 0;
}