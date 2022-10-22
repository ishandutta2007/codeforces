#include <bits/stdc++.h>
using namespace std;

int gdc(int a, int b){
    for(int i=min(a,b); i>=0; i--){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
}

int main() {
    int a ,b ,n,t=1;
    cin >> a >> b >> n;
    while(n){
        if(t){
            if(gdc(a,n)){
                n-=gdc(a,n);
                t=0;
            }
        }else{
            if(gdc(b,n)){
                n-=gdc(b,n);
                t=1;
            }
        }
    }
    cout << t;
    return 0;
}