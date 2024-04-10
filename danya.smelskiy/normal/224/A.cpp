#include <bits/stdc++.h>
using namespace std;
int n[5];
int a,b,c;
int main(){
    cin>>n[1]>>n[2]>>n[3];
    sort(n+1,n+4);
    a=n[1];
    b=n[2];
    c=n[3];
    for (int i=1;i<=a;++i){
        if (a%i!=0) continue;
        int j=a/i;
        if (b%i==0 && c%j==0){
            if (b/i==c/j){
                cout<<i*4+j*4+(b/i)*4;
                return 0;
            }
        }
        if (b%j==0 && c%i==0){
            if (b/j==c/i){
                cout<<i*4+j*4+(b/j)*4;
                return 0;
            }
        }
    }
}