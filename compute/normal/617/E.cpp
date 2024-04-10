#include<bits/stdc++.h>
using namespace std;
const int N=1e6*2;
int pos[N];
long long ans[N];
long long flag[N];
int a[N];
struct node{
    int l,r,id;
    bool operator < (const node &a)const{
        if(pos[a.l]==pos[l]) return r>a.r;
        return pos[l]>pos[a.l]; 
    }
}Q[N];
int n,m,k;
int L=1,R=0;
long long Ans=0;
void add(int x)
{
    Ans+=flag[a[x]^k];
    flag[a[x]]++;
}
void del(int x)
{
    flag[a[x]]--;
    Ans-=flag[a[x]^k];
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int block=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i-1]^a[i];
        pos[i]=i/block;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].id=i;
    }
    sort(Q+1,Q+m+1);
    flag[0]=1;
    for(int i=1;i<=m;i++)
    {
        while(L<Q[i].l)
        {
            del(L-1);
            L++;
        }
        while(L>Q[i].l)
        {
            L--;
            add(L-1);
        }
        while(R>Q[i].r)
        {
            del(R);
            R--;
        }
        while(R<Q[i].r)
        {
            R++;
            add(R);
        }
        ans[Q[i].id]=Ans;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}