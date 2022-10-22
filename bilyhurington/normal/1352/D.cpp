/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-05-09 23:33:15
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
int T,n,a[1010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=1,r=n,now=0,ans[2]={0,0},tmp=0,lst_mov[2]={0,0};
        while(l<=r){
            lst_mov[now]=0;
            while(l<=r&&lst_mov[now]<=lst_mov[now^1]){
                if(!now) lst_mov[now]+=a[l++];
                else lst_mov[now]+=a[r--];
            }
            ans[now]+=lst_mov[now];
            now^=1;tmp++;
        }
        printf("%d %d %d\n",tmp,ans[0],ans[1]);
    }
    return 0;
}