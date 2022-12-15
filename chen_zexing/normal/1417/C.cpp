#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#define LL long long
#define MAX 100005

using namespace std;
int a[300005],d[300005],r[300005],mx[300005],ans[300005],num[300005];
bool cmp(int a,int b){
    return mx[a]<mx[b]||mx[a]==mx[b]&&a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) r[i]=0,mx[i]=0,ans[i]=0,num[i]=i;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            d[i]=i-r[a[i]]-1;
            mx[a[i]]=max(mx[a[i]],d[i]);
            r[a[i]]=i;
        }
        for(int i=1;i<=n;i++) mx[i]=max(mx[i],n-r[i]);
        mx[n+1]=n;
        num[n+1]=n+1;
        sort(num+1,num+n+1,cmp);
        int now=1,v=INT_MAX;
        for(int i=1;i<=mx[num[1]];i++) ans[i]=-1;
        for(int i=1;i<=n;i++){
            v=min(v,num[i]);
            i++;
            for(;mx[num[i]]==mx[num[i-1]];i++);
            i--;
            for(int j=mx[num[i]]+1;j<=mx[num[i+1]];j++) ans[j]=v;
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}