#include<bits/stdc++.h>
using namespace std;
struct node{
    int flg;
    int d,id;
    bool operator <(const node &z)const{
        if(flg!=z.flg)return flg;
        return d>z.d;
    }
}a[1005];
int fa[1005],tt[1005],c[1005];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void work(){
    int n,i,j,x;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i].d);
        a[i].flg=1;
        a[i].id=i;
        fa[i]=i;
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;++i)tt[a[i].id]=i;
    int cnt=0;
    while(1){
        int q=a[1].id;
        if(!a[1].flg)break;
        a[1].flg=0;
        for(j=1;j<=a[1].d;++j){
            printf("? %d\n",q);
            fflush(stdout);
            scanf("%d",&x);
            ++cnt;
            if(a[tt[x]].flg == 0 || cnt>=n){
                fa[find(x)]=find(q);
                break;
            }
            else{
                a[tt[x]].flg=0;
                fa[find(x)]=find(q);
            }
        }
        sort(a+1,a+1+n);
        for(int ii=1;ii<=n;++ii)tt[a[ii].id]=ii;
        if(cnt==n)break;
    }
    printf("!");
    cnt=0;
    for(i=1;i<=n;++i)if(find(i)==i)c[find(i)]=++cnt;
    for(i=1;i<=n;++i)printf(" %d", c[find(i)]);
    puts("");
    fflush(stdout);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}