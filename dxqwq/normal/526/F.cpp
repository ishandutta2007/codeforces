#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s*f;
}
int a[600003],MX[600003][23],MN[600003][23],n;
inline void init(int l)
{
	MX[l][0]=MN[l][0]=a[l];
	for(int i=1; i<=20; i++) 
    MX[l][i]=max(MX[l][i-1],MX[min(l+(1<<(i-1)),n)][i-1]),
    MN[l][i]=min(MN[l][i-1],MN[min(l+(1<<(i-1)),n)][i-1]);
}
inline int check(int l,int r)
{
	int L=log(r-l+1)/log(2);
	return (r-l)==(max(MX[l][L],MX[min(r-(1<<L)+1,n)][L])-min(MN[l][L],MN[min(r-(1<<L)+1,n)][L]));
}//[l,r]
struct node//
{
    int L,R;//l,r
    int type;//type=0=1=-1
}tree[600003];
vector<int> e[600003];
int cnt,leaf[600003];//id
int s[600003],top;//
int smin[600003],topmin;//
int smax[600003],topmax;//minmax
int tag[2000003],ans[2000003];
int qwq[600003];
int d[600003],f[600003][23];
void push_down(int x)
{
	tag[x<<1]+=tag[x],tag[(x<<1)+1]+=tag[x],
	ans[x<<1]+=tag[x],ans[(x<<1)+1]+=tag[x],
	tag[x]=0;
	return ;
}
void update(int l,int r,int L,int R,int id,int val)
{
	if(L==l && r==R) 
	{
		tag[id]+=val;
		ans[id]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	push_down(id);
	if(R<=mid) update(l,mid,L,R,id<<1,val);
	else if(L>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
	else update(l,mid,L,mid,id<<1,val),update(mid+1,r,mid+1,R,(id<<1)+1,val);
    ans[id]=min(ans[(id<<1)],ans[(id<<1)+1]);
	return ;
}
int query(int l,int r,int id)
{
	if(l==r) return l;
	int mid=(l+r)>>1;
	push_down(id);
	if(ans[id<<1]==0) return query(l,mid,id<<1);
	return query(mid+1,r,(id<<1)+1);
}
inline bool check1(int x)
{
    if(tree[s[top]].type!=1) return 0;
    return check(qwq[s[top]],x);
}
inline bool check2(int x)
{
    return check(tree[s[top]].L,tree[x].R);
}
inline void init(int u,int father)
{
    d[u]=d[father]+1;
    for(int i=1; i<=20; i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        f[v][0]=u,init(v,u);
    }
}
inline int LCA(int x,int y)
{
    if(d[x]<d[y])swap(x,y);
    for(int i=20; i>=0; --i)
    {
        if(d[f[x][i]]>=d[y])x=f[x][i];
        if(x==y)return x;
    }
    for(int i=20; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline int ACL(int x,int y)
{
    for(int i=20; i>=0; --i) if(d[f[x][i]]>d[y]) x=f[x][i];
	return x;
}
void getans(int x,int y)
{
    if(x==y) 
    {
        printf("%d %d\n",tree[x].L,tree[x].L);
        return ;
    }
    int t=LCA(x,y);
    if(tree[t].type!=1) 
    {
        printf("%d %d\n",tree[t].L,tree[t].R);
    }
    else 
    {
        int p=ACL(x,t),q=ACL(y,t);
        printf("%d %d\n",tree[p].L,tree[q].R);
    }    
}
signed main()
{
	//freopen("test.in","r",stdin);
	//freopen("out.txt","w",stdout);
    n=read();
    for(int i=1,x; i<=n; i++) x=read(),a[x]=read();
    for(int i=n; i>=1; i--) init(i);
    for(int i=1; i<=n; i++) 
    {
        while(topmin&&a[i]<a[smin[topmin]]) update(1,n,smin[topmin-1]+1,smin[topmin],1,a[smin[topmin]]),--topmin;
        while(topmax&&a[i]>a[smax[topmax]]) update(1,n,smax[topmax-1]+1,smax[topmax],1,-a[smax[topmax]]),--topmax;
        update(1,n,smin[topmin]+1,i,1,-a[i]);
        update(1,n,smax[topmax]+1,i,1,a[i]);
        if(i!=1) update(1,n,1,i-1,1,-1);
        smin[++topmin]=i,smax[++topmax]=i;
        int now=++cnt,tmp,le=query(1,n,1);
        leaf[i]=now,tree[now].L=tree[now].R=i,tree[now].type=-1;
        while(top&&tree[now].L>=le)
        {
            if(check1(i))//Case 1 top 
            tmp=s[top--],e[tmp].push_back(now),
            tree[tmp].L=min(tree[tmp].L,tree[now].L),tree[tmp].R=max(tree[tmp].R,tree[now].R),now=tmp;
            else if(check2(now))//Case 2 top 
            {
                tmp=++cnt,e[tmp].push_back(now),e[tmp].push_back(s[top]),
                tree[tmp].L=tree[s[top--]].L,tree[tmp].R=tree[now].R,tree[tmp].type=1,qwq[tmp]=tree[now].L,now=tmp;
            }
            else if(top&&le<=tree[s[top]].L)
            {
                tmp=++cnt,e[tmp].push_back(now),tree[tmp].R=tree[now].R,tree[tmp].type=0;
                do tree[tmp].L=tree[s[top]].L,e[tmp].push_back(s[top--]); while(top&&check(tree[s[top]].R+1,tree[now].R)==0);
                now=tmp;
            } else break;
        }
        s[++top]=now;
    }
    long long ans=0;
    for(int i=1; i<=cnt; i++) if(tree[i].type==1) ans+=1ll*e[i].size()*(e[i].size()-1)/2;
    else ++ans;
    printf("%lld\n",ans);
    return 0;
}