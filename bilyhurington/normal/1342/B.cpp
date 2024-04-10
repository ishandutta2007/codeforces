/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-26 22:58:27
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
int T,n;
char t[110],s[210];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",t+1);
        n=strlen(t+1);
        bool pd=0;
        for(int i=1;i<n;i++) if(t[i]!=t[i+1]) pd=1;
        if(!pd){for(int i=1;i<=n;i++) printf("%c",t[i]);printf("\n");continue;}
        for(int i=1;i<=n;i++) printf("01");
        printf("\n");
    }
    return 0;
}