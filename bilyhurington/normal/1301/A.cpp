/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 22:32:30
 * @LastEditors  : BilyHurington
 * @LastEditTime : 2020-02-14 14:42:30
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
char a[110],b[110],c[110];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s %s %s",a+1,b+1,c+1);
        n=strlen(a+1);
        bool pd=1;
        for(int i=1;i<=n;i++){
            if(a[i]==c[i]||b[i]==c[i]) continue;
            pd=0;
            break;
        }
        if(pd) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
//test