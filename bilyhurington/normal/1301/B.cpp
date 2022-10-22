/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 22:32:37
 * @LastEditors  : BilyHurington
 * @LastEditTime : 2020-02-13 22:52:01
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
int T,n,a[100010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0,k=0,minn=(1e9)+1,maxn=-1;
        for(int i=1;i<n;i++){
            if(a[i]==-1&&a[i+1]==-1) continue;
            if(a[i]!=-1&&a[i+1]!=-1){
                ans=max(ans,abs(a[i]-a[i+1]));
                continue;
            }
            // printf("%d %d\n",a[i],a[i+1]);
            int x=a[i]+a[i+1]+1;
            minn=min(minn,x);
            maxn=max(maxn,x);
        }
        if(maxn==-1&&minn==1e9+1) printf("%d %d\n",ans,k);
        else printf("%d %d\n",max(maxn-(maxn+minn)/2,ans),(maxn+minn)/2);
    }
    return 0;
}