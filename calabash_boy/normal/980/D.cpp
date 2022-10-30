#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+100;
typedef long long LL;
int fa[maxn];
int cnt[maxn];
int ans[maxn];
int flag[maxn];
int a[maxn],n;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool isSquare(LL x){
    if (x<=0)return false;
    LL temp = sqrt(1.0*x);
    for (LL i = temp-2;i<=temp+2;i++){
        if (i*i==x)return true;
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        fa[i]=i;
    }
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i!=j&&isSquare(1LL*a[i]*a[j])){
                fa[find(i)]=find(j);
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (a[i]==0)a[i]=0;
        else
        a[i] = find(i);

    }
    for (int i=1;i<=n;i++){
        int now =1;
        cnt[a[i]]=i;
        ans[1]++;
        bool flag = false;
        for (int j=i+1;j<=n;j++){
            if (cnt[a[j]]!=i){
                cnt[a[j]]=i;
                if (now==1&&a[i]==0&&a[j]!=0&&!flag||a[j]==0)flag=true;
                else
                now++;
            }
            ans[now]++;
        }
    }
    for (int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}