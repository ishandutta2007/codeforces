/*
 * @Author: BilyHurington
 * @Date: 2020-05-31 22:36:40
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-06-01 00:23:41
 */ 
#include<bits/stdc++.h>
using namespace std;
int T,n,k,ans[1010],maxn;
vector<int> v[1010];
bool tg[1010];
int find_mx(int l,int r){
    if(l==r) return l;
    int mid=(l+r)>>1;
    printf("? %d ",mid-l+1);
    for(int i=l;i<=mid;i++) printf("%d ",i);printf("\n");
    fflush(stdout);
    int x;scanf("%d",&x);
    if(x==maxn) return find_mx(l,mid);
    else return find_mx(mid+1,r);
}
void solve(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++){
        v[i].clear();
        int c;scanf("%d",&c);
        for(int j=1,x;j<=c;j++) scanf("%d",&x),v[i].push_back(x);
    }
    printf("? %d ",n);
    for(int i=1;i<=n;i++) printf("%d ",i);
    printf("\n");
    fflush(stdout);
    scanf("%d",&maxn);//printf("%d\n",maxn);
    int tmp=find_mx(1,n);
    // printf("%d\n",tmp);
    for(int i=1;i<=k;i++){
        bool tag=1;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==tmp) tag=0;
        }
        if(tag){ans[i]=maxn;continue;}
        // printf("%d\n",tag);
        printf("? %d ",n-v[i].size());
        memset(tg,0,sizeof(tg));
        for(int j=0;j<v[i].size();j++) tg[v[i][j]]=1;
        for(int j=1;j<=n;j++) if(!tg[j]) printf("%d ",j);
        printf("\n");
        fflush(stdout);
        scanf("%d",&ans[i]);
    }
    printf("! ");
    for(int i=1;i<=k;i++) printf("%d ",ans[i]);
    printf("\n");fflush(stdout);
    string s;cin>>s;
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}