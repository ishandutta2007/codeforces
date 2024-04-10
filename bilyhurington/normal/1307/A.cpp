/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-17 23:43:31
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
int T,n,d,a[110];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=2;i<=n;i++){
            while(d>=i-1&&a[i]){
                a[1]++;
                d-=i-1;
                a[i]--;
            }
        }
        printf("%d\n",a[1]);
    }
    return 0;
}