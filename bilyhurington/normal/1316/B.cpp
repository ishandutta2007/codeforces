/*
 * @Author: BilyHurington
 * @Date: 2020-03-04 22:39:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-04 23:13:20
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,n,k;
char s[5010],ans[5010],ch[5010];
bool chk(){
    if(!k) return 1;
    for(int i=1;i<=n;i++){
        if(ans[i]>ch[i]) return 1;
        if(ans[i]<ch[i]) return 0;
    }
    return 0;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s+1);
        k=0;
        for(int i=1;i<=n;i++){
            int tot=0;
            for(int j=i;j<=n;j++) ch[++tot]=s[j];
            if((n-i)%2==0){
                for(int j=1;j<i;j++) ch[++tot]=s[i-j];
            }
            else{
                for(int j=1;j<i;j++) ch[++tot]=s[j];
            }
            if(chk()){
                k=i;
                for(int j=1;j<=n;j++) ans[j]=ch[j];
            }
        }
        for(int i=1;i<=n;i++) printf("%c",ans[i]);
        printf("\n%d\n",k);
    }
    return 0;
}