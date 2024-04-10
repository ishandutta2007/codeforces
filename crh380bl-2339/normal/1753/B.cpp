#include<bits/stdc++.h>
using namespace std;
int a[500005];
void work(){
    int n,x,i,j,y;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;++i){
        scanf("%d",&y);
        ++a[y];
    }
    i=1;
    while(1){
        a[i+1]+=a[i]/(i+1);
        a[i]%=(i+1);
        if(a[i])break;
        ++i;
    }
    //printf("%d\n",i);
    if(i>=x)puts("Yes");
    else puts("No");
}
int main(){
    int T;
    T=1;
    while(T--){
        work();
    }
    return 0;
}