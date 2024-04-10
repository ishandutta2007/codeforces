/*
 * @Author: BilyHurington
 * @Date: 2020-09-30 22:35:11
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-30 22:58:04
 */
#include<bits/stdc++.h>
using namespace std;
int T,n,a[110],b[110],c[110],ans[110];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&c[i]);
        }
        ans[1]=a[1];
        for(int i=2;i<n;i++){
            if(a[i]!=ans[i-1]) ans[i]=a[i];
            else if(b[i]!=ans[i-1]) ans[i]=b[i];
            else if(c[i]!=ans[i-1]) ans[i]=c[i];
        }
        if(a[n]!=ans[n-1]&&a[n]!=ans[1]) ans[n]=a[n];
        else if(b[n]!=ans[n-1]&&b[n]!=ans[1]) ans[n]=b[n];
        else if(c[n]!=ans[n-1]&&c[n]!=ans[1]) ans[n]=c[n];
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);printf("\n");
    }
    return 0;
}