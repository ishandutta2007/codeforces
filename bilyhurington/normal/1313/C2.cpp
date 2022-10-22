/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-23 18:04:52
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
int n,top;
long long ans1[500010],ans2[500010],a[500010],l[500010];
pair<int,long long> st[500010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        while(top&&a[i]<=st[top].second) top--;
        if(i==1) ans1[i]=0;
        else ans1[i]=ans1[st[top].first]+a[st[top].first]+a[i]*(i-st[top].first-1);
        st[++top]=make_pair(i,a[i]);
    }
    top=0;
    st[0].first=n+1;
    for(int i=n;i>=1;i--){
        while(top&&a[i]<=st[top].second) top--;
        if(i==n) ans2[i]=0;
        else ans2[i]=ans2[st[top].first]+a[st[top].first]+a[i]*(st[top].first-i-1);
        st[++top]=make_pair(i,a[i]);
    }
    long long ans=0,maxn_i=1;
    for(int i=1;i<=n;i++){
        if(ans<ans1[i]+ans2[i]+a[i]){
            ans=ans1[i]+ans2[i]+a[i];
            maxn_i=i;
        }
    }
    for(int j=maxn_i-1,maxn=a[maxn_i];j>=1;j--){
        maxn=min(maxn,(int)a[j]);
        l[j]=maxn;
    }
    for(int j=maxn_i+1,maxn=a[maxn_i];j<=n;j++){
        maxn=min(maxn,(int)a[j]);
        l[j]=maxn;
    }
    l[maxn_i]=a[maxn_i];
    for(int i=1;i<=n;i++) printf("%lld ",l[i]);
    return 0;
}