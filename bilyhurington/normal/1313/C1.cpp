/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-23 17:46:47
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
int n,a[1010],l[1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    long long maxn_ans=0;
    int maxn_i=1;
    for(int i=1;i<=n;i++){
        long long ans=a[i];
        for(int j=i-1,maxn=a[i];j>=1;j--){
            maxn=min(maxn,a[j]);
            ans+=maxn;
        }
        for(int j=i+1,maxn=a[i];j<=n;j++){
            maxn=min(maxn,a[j]);
            ans+=maxn;
        }
        if(ans>maxn_ans){
            maxn_ans=ans;
            maxn_i=i;
        }
    }
    for(int j=maxn_i-1,maxn=a[maxn_i];j>=1;j--){
        maxn=min(maxn,a[j]);
        l[j]=maxn;
    }
    for(int j=maxn_i+1,maxn=a[maxn_i];j<=n;j++){
        maxn=min(maxn,a[j]);
        l[j]=maxn;
    }
    l[maxn_i]=a[maxn_i];
    for(int i=1;i<=n;i++) printf("%d ",l[i]);
    return 0;
}