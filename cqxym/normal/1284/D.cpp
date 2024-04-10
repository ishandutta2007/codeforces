#include<bits/stdc++.h>
using namespace std;
const int M=4e5+5;
typedef long long ll;
#define pb push_back
#define lson root<<1,l,midd
#define rson root<<1|1,midd+1,r
struct tree{
    int val,lazy;
}tr[M<<2];
vector<int>l[M],r[M],lisan;
struct node{
    int l,r,id;
}a[M],b[M];
int n;
void build(int root,int l,int r){
    if(l==r){
        tr[root].val=tr[root].lazy=0;
        return ;
    }
    int midd=(l+r)>>1;
    build(lson);
    build(rson);
    tr[root].val=tr[root].lazy=0;
}
void pushdown(int root){
    int x=tr[root].lazy;
    tr[root<<1].val+=x;
    tr[root<<1|1].val+=x;
    tr[root<<1].lazy+=x;
    tr[root<<1|1].lazy+=x;
    tr[root].lazy=0;
}
void up(int root){
    tr[root].val=max(tr[root<<1].val,tr[root<<1|1].val);
}
void update(int L,int R,int val,int root,int l,int r){
    if(L<=l&&r<=R){
        tr[root].val+=val;
        tr[root].lazy+=val;
        return ;
    }
    if(tr[root].lazy!=0)
        pushdown(root);
    int midd=(l+r)>>1;
    if(L<=midd)
        update(L,R,val,lson);
    if(R>midd)
        update(L,R,val,rson);
    up(root);
}
int query(int L,int R,int root,int l,int r){
    if(L<=l&&r<=R)
        return tr[root].val;
    if(tr[root].lazy!=0)
        pushdown(root);
    int maxx=0,midd=(l+r)>>1;
    if(L<=midd)
        maxx=max(maxx,query(L,R,lson));
    if(R>midd)
        maxx=max(maxx,query(L,R,rson));
    up(root);
    return maxx;
}
bool solve(node *a,node *b){
    int len=lisan.size();
    build(1,1,len);
    for(int i=1;i<=len;i++)
        l[i].clear(),r[i].clear();
    for(int i=1;i<=n;i++){
        l[a[i].l].pb(i);
        r[a[i].r].pb(i);
    }
    int countt=0;
    for(int i=1;i<=len;i++){
        for(int j=0;j<l[i].size();j++){
            int id=l[i][j];
            int L=b[id].l,R=b[id].r;
            int mx=query(L,R,1,1,len);
            if(mx!=countt)
                return false; 
            update(L,R,1,1,1,len);
            countt++;
        }
        for(int j=0;j<r[i].size();j++){
            int id=r[i][j];
            int L=b[id].l,R=b[id].r;
            update(L,R,-1,1,1,len);
            countt--;
        }
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int x1,x2,y1,y2,i=1;i<=n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        lisan.pb(x1),lisan.pb(y1),lisan.pb(x2),lisan.pb(y2);
        a[i].l=x1,a[i].r=y1,a[i].id=i;
        b[i].l=x2,b[i].r=y2,b[i].id=i;
    }
    sort(lisan.begin(),lisan.end());
    lisan.erase(unique(lisan.begin(),lisan.end()),lisan.end());
    for(int i=1;i<=n;i++){
        a[i].l=lower_bound(lisan.begin(),lisan.end(),a[i].l)-lisan.begin()+1;
        a[i].r=lower_bound(lisan.begin(),lisan.end(),a[i].r)-lisan.begin()+1;
        b[i].l=lower_bound(lisan.begin(),lisan.end(),b[i].l)-lisan.begin()+1;
        b[i].r=lower_bound(lisan.begin(),lisan.end(),b[i].r)-lisan.begin()+1;
    }
    if(solve(a,b)&&solve(b,a))
        puts("YES");
    else
        puts("NO");
    return 0;
}