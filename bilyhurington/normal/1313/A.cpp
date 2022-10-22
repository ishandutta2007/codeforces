/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-23 17:13:50
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
int T,num[3],a[8][3]={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,1,1}};
int main(){
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%d %d %d",&num[0],&num[1],&num[2]);
        for(int i=0;i<(1<<7);i++){
            int p[3]={0,0,0},sum=0;
            for(int j=0;j<7;j++){
                if((1<<j)&i){
                    sum++;
                    for(int k=0;k<3;k++) p[k]+=a[j][k];
                }
            }
            if(p[0]>num[0]||p[1]>num[1]||p[2]>num[2]) continue;
            ans=max(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}