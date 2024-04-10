#include<bits/stdc++.h>
#define rec const int&
#define Upd(x) (aaa[x].mn=min(aaa[x<<1].mn,aaa[x<<1|1].mn))
using namespace std;
const int INF=1e9;
int aaaaaa;
struct node{
    int l,r,mn;
}aaa[1200010];
int q,n,a[300010],g[300010],get_ans[300010],assis[300010];
vector<int>p[300010];
int askk(rec x,rec l,rec r){
    if(l>r)return INF;
    if(aaa[x].l==l&&aaa[x].r==r)return aaa[x].mn;
    int mid=aaa[x].l+aaa[x].r>>1;
    return l>mid?askk(x<<1|1,l,r):(r<=mid?askk(x<<1,l,r):min(askk(x<<1,l,mid),askk(x<<1|1,mid+1,r)));
}
void doit(rec x,rec id,rec v){
    if(aaa[x].l==aaa[x].r)return(void)(aaa[x].mn=v);
    int mid=aaa[x].l+aaa[x].r>>1;
    id<=mid?doit(x<<1,id,v):doit(x<<1|1,id,v),Upd(x);
}
void mmade(rec x,rec l,rec r){
    aaa[x].l=l,aaa[x].r=r;
    if(l==r)return(void)(aaa[x].mn=a[l]);
    int mid=l+r>>1;
    mmade(x<<1,l,mid),mmade(x<<1|1,mid+1,r),Upd(x);
}
int main(){
    scanf("%d",&q);
    for(int cnt=1;cnt<=q;++cnt){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]),get_ans[a[i]]<cnt?p[a[i]].clear(),assis[a[i]]=0,get_ans[a[i]]=cnt:0,p[a[i]].push_back(i);
        mmade(1,1,n);
        for(int i=1;i<=n;++i)scanf("%d",&g[i]);
        for(int i=1;i<=n;++i){
            if(get_ans[g[i]]<cnt||assis[g[i]]>=p[g[i]].size()){puts("NO");goto END;}
            if(askk(1,1,p[g[i]][assis[g[i]]]-1)<g[i]){puts("NO");goto END;}
            doit(1,p[g[i]][assis[g[i]]],INF),++assis[g[i]];
        }
        puts("YES");
        END:
        ;
    }
    return 0;
}