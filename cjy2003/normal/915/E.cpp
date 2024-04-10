#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,cnt[15000000],tot,lson[15000000],rson[15000000];
int bj[15000000],rt;
void pushdown(int k,int l,int r)
{
    if(!lson[k])lson[k]=++tot;
    if(!rson[k])rson[k]=++tot;
    bj[lson[k]]=bj[rson[k]]=bj[k];
    if(bj[k]==2)cnt[lson[k]]=0,cnt[rson[k]]=0;
    else cnt[lson[k]]=(l+r>>1)-l+1,cnt[rson[k]]=r-(l+r>>1);
    bj[k]=0;
}
void upd(int &k,int l,int r,int ll,int rr,int opt)
{
    if(l>rr||r<ll)return ;
    if(!k)k=++tot;
    if(l>=ll&&r<=rr)
    {
        bj[k]=opt;
        if(opt==1)cnt[k]=r-l+1;
        else cnt[k]=0;
        return ;
    }
    if(bj[k])pushdown(k,l,r);
    upd(lson[k],l,l+r>>1,ll,rr,opt);
    upd(rson[k],(l+r>>1)+1,r,ll,rr,opt);
    cnt[k]=cnt[lson[k]]+cnt[rson[k]];
}
int main()
{
    scanf("%d %d",&n,&m);
    int c,x,y;
    while(m--)
    {
        scanf("%d %d %d",&x,&y,&c);
        if(c==1)upd(rt,1,n,x,y,1);
        else upd(rt,1,n,x,y,2);
        printf("%d\n",n-cnt[1]);
    //    for(int i=1;i<=tot;++i)
    //        printf("%d %d %d %d\n",i,cnt[i],lson[i],rson[i]);
    }
 	return 0;
}