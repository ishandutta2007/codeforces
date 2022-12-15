#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        if(n%2==0){
            for(int i=n/2;i;i--) printf("%d %d ",i,i+n/2);
            puts("");
        }
        else{
            for(int i=n/2+1;i>1;i--) printf("%d %d ",i,i+n/2);
            puts("1");
        }
    }
    return 0;
}