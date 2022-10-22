#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,r=0;
    cin >> n >> k;
    for(int i=1; ; i++){
        if(2*n<=k*i){
            r+=i;
            break;
        }
    }
    for(int i=1; ; i++){
        if(5*n<=k*i){
            r+=i;
            break;
        }
    }
    for(int i=1; ; i++){
        if(8*n<=k*i){
            r+=i;
            break;
        }
    }
    cout << r;
    return 0;
}