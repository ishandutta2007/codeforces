#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#define LL long long

using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int l,r;
        int n,x,m,c,d;
        cin>>n>>x>>m;
        l=r=x;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&c,&d);
            if(c<=r&&d>=l) l=min(l,c),r=max(r,d);
        }
        printf("%d\n",r-l+1);
    }
    return 0;
}