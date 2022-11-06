#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n&1){
            puts("-1");
        }
        else{
            printf("0 %d %d\n",n/2,n/2);
        }
    }
    return 0;
}