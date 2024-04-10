#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int s[maxn];
int n,k;
int fa[maxn],sz[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
};
int main(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",s+i);
    }
    for (int i=0;i<=255;i++){
        fa[i]=i;
        sz[i]=1;
    }
    for (int i=0;i<n;i++){
        int now = s[i];
        int nowCnt= sz[find(now)];
        while (true){
            int temp = find(now)-1;
            if (temp<0)break;
            int tempCnt = sz[find(temp)];
            if (tempCnt+nowCnt>k)break;
            nowCnt+=tempCnt;

            fa[find(now)]=find(temp);
            sz[find(temp)]=nowCnt;
            now = find(temp);
        }
    }
    for (int i=0;i<n;i++){
        printf("%d ",find(s[i]));
    }
    return 0;
}