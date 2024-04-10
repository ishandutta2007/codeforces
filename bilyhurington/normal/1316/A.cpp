/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-04 22:38:23
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
int T,n,m,a[1010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        int sum=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        printf("%d\n",min(sum,m));
    }
    return 0;
}