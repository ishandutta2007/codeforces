#include<bits/stdc++.h>
using namespace std;
int a[100005];
void work(){
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        a[x]=i;
    }
    for(i=1;i<=n;++i){
        printf("%d ",a[n-i+1]);
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}