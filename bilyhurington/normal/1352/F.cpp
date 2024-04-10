/*
 * @Author: BilyHurington
 * @Date: 2020-05-09 22:50:47
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-09 22:55:12
 */
#include<bits/stdc++.h>
using namespace std;
int T,n0,n1,n2;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n0,&n1,&n2);
        if(!n1){
            if(n0) for(int i=1;i<=n0+1;i++) printf("0");
            else for(int i=1;i<=n2+1;i++) printf("1");
            printf("\n");
            continue;
        }
        for(int i=1;i<=n0+1;i++) printf("0");
        for(int i=1;i<=n2+1;i++) printf("1");
        for(int i=1;i<n1;i++){
            if(i%2) printf("0");
            else printf("1");
        }
        printf("\n");
    }
    return 0;
}