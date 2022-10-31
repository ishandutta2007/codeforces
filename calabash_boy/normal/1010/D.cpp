#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
int type[maxn];
int son[maxn][2];
int n;
char s[20];
int ans[maxn];
int val[maxn];
int d[maxn];
int fa[maxn];
bool flag[maxn];
int cnt[maxn];
queue<int>Q;
void dfs(int u){
    if (u!=1&&flag[fa[u]]){
        switch (type[fa[u]]){
            case 1:{
                if (val[fa[u]]==1||cnt[fa[u]]==1&&val[u]==0){
                    flag[u]=1;
                }
                break;
            }
            case 2:{
                if (cnt[fa[u]]==1&&val[u]==1||val[fa[u]]==0){
                    flag[u]=1;
                }
                break;
            }
            case 3:{
                flag[u]=1;
                break;
            }
            case 4:{
                flag[u]=1;
                break;
            }
        }
    }
    if (son[u][0]){
        dfs(son[u][0]);
    }
    if (son[u][1]){
        dfs(son[u][1]);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",s);
        if (s[0]=='A'){
            int l,r;
            scanf("%d%d",&l,&r);
            son[i][0] = l;
            son[i][1]=r;
            type[i]=1;
            fa[son[i][0]]=i;
            fa[son[i][1]]=i;
            d[i]=2;
        }else if (s[0]=='O'){
            scanf("%d%d",&son[i][0],&son[i][1]);
            type[i]=2;
            fa[son[i][0]]=i;
            fa[son[i][1]]=i;
            d[i]=2;
        }else if (s[0]=='X'){
            scanf("%d%d",&son[i][0],&son[i][1]);
            type[i]=3;
            fa[son[i][0]]=i;
            fa[son[i][1]]=i;
            d[i]=2;
        }else if (s[0]=='N'){
            scanf("%d",&son[i][0]);
            type[i]=4;
            fa[son[i][0]]=i;
            d[i]=1;
        }else{
            scanf("%d",&val[i]);
            type[i]=5;
            Q.push(i);
        }
    }
    while (!Q.empty()){
        int head = Q.front();
        Q.pop();
        if (d[fa[head]]==2){
            d[fa[head]]--;
            val[fa[head]]=val[head];
        }else if (d[fa[head]]==1){
            d[fa[head]]--;
            if (type[fa[head]]==4){
                val[fa[head]]=!val[head];
            }else if (type[fa[head]]==1){
                val[fa[head]]&=val[head];
            }else if (type[fa[head]]==2){
                val[fa[head]]|=val[head];
            }else if (type[fa[head]]==3){
                val[fa[head]]^=val[head];
            }
        }
        if (d[fa[head]]==0&&fa[head]!=0){
            Q.push(fa[head]);
        }
    }
    for (int i=1;i<=n;i++){
      //  printf("val[%d]=%d\n",i,val[i]);
       // printf("son[%d][0]=%d\n",i,son[i][0]);
    }
    for (int i=1;i<=n;i++){
        cnt[fa[i]]+=val[i];
    }
    flag[1]=1;
    dfs(1);
    flag[1]=1;
    for (int i=1;i<=n;i++){
       // printf("flag[%d]=%d\n",i,flag[i]);
    }
    for (int i=1;i<=n;i++){
        if (type[i]==5){
            if (flag[i]){
                printf("%d",!val[1]);
            }else{
                printf("%d",val[1]);
            }
        }
    }
    return 0;
}