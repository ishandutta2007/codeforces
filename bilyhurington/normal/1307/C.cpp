/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-18 01:21:23
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
int n;
long long ch[210],num[210][210];
char s[100010];
int main(){
    while(scanf(" %c",&s[++n])!=EOF);
    long long maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<128;j++) num[j][s[i]]+=ch[j];
        ch[s[i]]++;
    }
    for(int i=0;i<128;i++) maxn=max(maxn,ch[i]);
    for(int i=0;i<128;i++) for(int j=0;j<128;j++) maxn=max(maxn,num[i][j]);
    printf("%lld\n",maxn);
    return 0;
}