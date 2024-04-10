#include<bits/stdc++.h>
using namespace std;
int t,n,x,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&x,&a,&b);
        printf("%d\n",min(abs(b-a)+x,n-1));
    }
    return 0;
}