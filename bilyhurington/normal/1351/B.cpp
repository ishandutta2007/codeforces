/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-07 22:11:23
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
int T,a[2],b[2];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d",&a[0],&a[1],&b[0],&b[1]);
        bool pd=0;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++){
            if(a[i]==b[j]){
                // printf("%d %d\n",i,j);
                if(a[i]*3==a[0]+a[1]+b[0]+b[1]){printf("Yes\n");pd=1;break;}
            }
        }
        if(!pd) printf("No\n");
    }
    return 0;
}