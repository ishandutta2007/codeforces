#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int r(int n,int m){
    if(n==1||m==1){
        return 1;
    }
    return r(n-1,m)+r(n,m-1);
}
int main(){
    int n;
    cin>>n;
    cout<<r(n,n);
    return 0;
}