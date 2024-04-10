#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n;
        cin>>n;
        if(n==1) puts("3");
        else{
            int bonus;
            if(n%3==0) bonus=3;
            else if(n%3==1) bonus=0;
            else bonus=1;
            printf("%d\n",4+(n-1)/3*4+bonus);
        }
    }
    return 0;
}