#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
int n,m,i,j,x,y,a,b,tp[300005],fa[300005],sz[300005],son[300005],dep[300005],fi[300005],ed[300005],ti;
unsigned long long pw[300005],f[300005],g[300005],e=1e9+9;
long long fff[300005],ggg[300005],ppp[300005],eee=1e6+33,mod=998244353;
string st;
char s[300005];
vector<int> bi[300005];
void dfs1(int x,int p)
{
    sz[x]=1;fa[x]=p;
    ff(bi[x],it) if (*it!=p)
    {
        dep[*it]=dep[x]+1;
        dfs1(*it,x);sz[x]+=sz[*it];
        if (!son[x]||sz[*it]>sz[son[x]]){
            son[x]=*it;
        }
    }
}
void dfs2(int x,int t)
{
    tp[x]=t;fi[x]=++ti;s[fi[x]]=st[x];
    if (son[x]) dfs2(son[x],t);
    ff(bi[x],it) if (*it!=fa[x]&&*it!=son[x]){
        dfs2(*it,*it);
    }
    ed[x]=ti;
}
vector<int> seq1,seq2,seq3,seq4;
unsigned long long qtree1(int l,int r)
{
    return f[r]-f[l-1]*pw[r-l+1];
}
unsigned long long qtree2(int l,int r)
{
    return g[l]-g[r+1]*pw[r-l+1];
}
long long qtree3(int l,int r)
{
    long long ans=(fff[r]-fff[l-1]*ppp[r-l+1])%mod;
    if (ans<0) ans+=mod;
    return ans;
}
long long qtree4(int l,int r)
{
    long long ans=(ggg[l]-ggg[r+1]*ppp[r-l+1])%mod;
    if (ans<0) ans+=mod;
    return ans;
}
unsigned long long qtree(int l,int r)
{
	if (l<=r) return qtree1(l,r); else return qtree2(r,l);
}
long long qtree0(int l,int r)
{
	if (l<=r) return qtree3(l,r); else return qtree4(r,l);
}
int sgn(int x)
{
	if (x>=0) return 1;
	return -1;
}
int query2(int x,int y,int a,int b)
{
	int l=0,r=min(abs(y-x)+1,abs(b-a)+1),ans=0,mid,f1=sgn(y-x),f2=sgn(b-a);
	while (l<r)
	{
		mid=(l+r)/2;
		if (qtree(x,x+mid*f1)==qtree(a,a+mid*f2)&&qtree0(x,x+mid*f1)==qtree0(a,a+mid*f2))
		{
			l=ans=mid+1;
		}
		else r=mid;
	}
	return ans;
}
int query(int x,int y,int a,int b)
{
    seq1.clear();seq2.clear();
    vector<int> tseq1,tseq2;
    while (tp[x]!=tp[y])
    {
        if (dep[tp[x]]<dep[tp[y]])
        {
            tseq1.push_back(fi[tp[y]]);
            tseq2.push_back(fi[y]);
            y=fa[tp[y]];
        }
        else
        {
            seq1.push_back(fi[x]);
            seq2.push_back(fi[tp[x]]);
            x=fa[tp[x]];
        }
    }
    if (dep[x]>dep[y])
    {
        seq1.push_back(fi[x]);
        seq2.push_back(fi[y]);
    }
    else
    {
        tseq1.push_back(fi[x]);
        tseq2.push_back(fi[y]);
    }
    while (!tseq1.empty()){
        seq1.push_back(tseq1.back());
        seq2.push_back(tseq2.back());
        tseq1.pop_back();
        tseq2.pop_back();
    }
    seq3.clear();seq4.clear();
    vector<int> tseq3,tseq4;
    x=a;y=b;
    while (tp[x]!=tp[y])
    {
        if (dep[tp[x]]<dep[tp[y]])
        {
            tseq3.push_back(fi[tp[y]]);
            tseq4.push_back(fi[y]);
            y=fa[tp[y]];
        }
        else
        {
            seq3.push_back(fi[x]);
            seq4.push_back(fi[tp[x]]);
            x=fa[tp[x]];
        }
    }
    if (dep[x]>dep[y])
    {
        seq3.push_back(fi[x]);
        seq4.push_back(fi[y]);
    }
    else
    {
        tseq3.push_back(fi[x]);
        tseq4.push_back(fi[y]);
    }
    while (!tseq3.empty()){
        seq3.push_back(tseq3.back());
        seq4.push_back(tseq4.back());
        tseq3.pop_back();
        tseq4.pop_back();
    }
//    ff(seq1,it) cerr<<*it<<' ';cerr<<endl;
//    ff(seq2,it) cerr<<*it<<' ';cerr<<endl;
//    ff(seq3,it) cerr<<*it<<' ';cerr<<endl;
//    ff(seq4,it) cerr<<*it<<' ';cerr<<endl; 
    int i=0,j=0,ans=0;
    while (i<seq1.size()&&j<seq3.size())
    {
    	int l1=abs(seq1[i]-seq2[i])+1,l2=abs(seq3[j]-seq4[j])+1;
    	int t=min(l1,l2);
    	int f1=sgn(seq2[i]-seq1[i]);
    	int f2=sgn(seq4[j]-seq3[j]);
    	if ((qtree(seq1[i],seq1[i]+f1*(t-1))!=qtree(seq3[j],seq3[j]+f2*(t-1)))||(qtree0(seq1[i],seq1[i]+f1*(t-1))!=qtree0(seq3[j],seq3[j]+f2*(t-1)))){
    		return query2(seq1[i],seq1[i]+f1*(t-1),seq3[j],seq3[j]+f2*(t-1))+ans;
    	}
    	seq1[i]+=f1*t;seq3[j]+=f2*t;
    	if (l1==t) i++;
    	if (l2==t) j++;
    	ans+=t;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    rdst(st,300005);st=" "+st;
    pw[0]=ppp[0]=1;
    fz1(i,n){
        pw[i]=pw[i-1]*e;
        ppp[i]=ppp[i-1]*eee%mod;
    }
    fz1(i,n-1)
    {
        scanf("%d%d",&x,&y);
        bi[x].push_back(y);
        bi[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,1);
    fz1(i,n){
        f[i]=f[i-1]*e+s[i];
        fff[i]=(fff[i-1]*eee+s[i])%mod;
    }
    fd1(i,n){
        g[i]=g[i+1]*e+s[i];
        ggg[i]=(ggg[i+1]*eee+s[i])%mod;
    }
    scanf("%d",&m);
    while (m--){
        scanf("%d%d%d%d",&x,&y,&a,&b);
        printf("%d\n",query(x,y,a,b));
    }
    return 0;
}