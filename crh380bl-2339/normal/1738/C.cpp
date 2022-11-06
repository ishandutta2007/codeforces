#include<bits/stdc++.h>
using namespace std;
int a[100];
void work(){
    int n,i,x;
    a[0]=a[1]=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&x);
        ++a[x&1];
    }
    if(a[1]%4==0)puts("Alice");
    else if(a[1]%4==2)puts("Bob");
    else if((a[1]%4==3))puts("Alice");
    else if(a[0]%2==0)puts("Bob");
    else puts("Alice");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}