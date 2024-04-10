#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,r;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&r);if(a>b)swap(a,b);
        printf("%d\n",max(b-max(a,c+r),0)+max(min(b,c-r)-a,0));
    }
    return 0;
}