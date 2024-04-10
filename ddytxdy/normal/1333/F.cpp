#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,mindiv[N],p[N],tot,cnt[N];
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(!mindiv[i])p[++tot]=mindiv[i]=i;
        for(int j=1,y;j<=tot&&p[j]<=mindiv[i]&&(y=p[j]*i)<=n;j++)
            mindiv[y]=p[j];
    }
    for(int i=2;i<=n;i++)cnt[i/mindiv[i]]++;
    for(int i=1;i<=n;i++)for(int j=1;j<=cnt[i];j++)printf("%d ",i);
    return 0;
}