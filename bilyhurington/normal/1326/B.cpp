/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-19 22:45:31
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
int n,b[200010];
int main(){
    scanf("%d",&n);
    int maxn=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        int x=b[i]+maxn;
        maxn=max(maxn,x);
        printf("%d ",x);
    }
    return 0;
}