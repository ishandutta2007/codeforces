// Problem: C. DZY Loves Colors
// Contest: Codeforces - Codeforces Round #254 (Div. 1)
// URL: https://codeforces.com/problemset/problem/444/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,m;
int a[1000003],tag[4000003],ans[4000003];
void build(int l,int r,int id)
{
	if(l==r) return (void)(ans[id]=a[l]);
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1);
	ans[id]=ans[id<<1]+ans[(id<<1)+1];
	return ;
}
void push_down(int x,int l1,int l2)
{
	tag[x<<1]+=tag[x],tag[(x<<1)+1]+=tag[x];
	ans[x<<1]+=tag[x]*l1,ans[(x<<1)+1]+=tag[x]*l2;
	tag[x]=0;
	return ;
}
void update(int l,int r,int L,int R,int id,int val)
{
	if(L<=l && r<=R) 
	{
		tag[id]+=val;
		ans[id]+=(r-l+1)*val;
		return ;
	}
	int mid=(l+r)>>1;
	push_down(id,mid-l+1,r-mid);
	if(L<=mid) update(l,mid,L,R,id<<1,val);
	if(R>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
	ans[id]=ans[(id<<1)]+ans[(id<<1)+1];
	return ;
}
int query(int l,int r,int L,int R,int id)
{
	if(L<=l && r<=R) return ans[id];
	int mid=(l+r)>>1;
	push_down(id,mid-l+1,r-mid);
	int res=0;
	if(L<=mid) res+=query(l,mid,L,R,id<<1);
	if(R>=mid+1) res+=query(mid+1,r,L,R,(id<<1)+1);
	return res;
}
struct Node{
    int l,r,val;
    Node(int a=-1,int b=-1,int c=0){l=a,r=b,val=c;}
    bool operator<(const Node&a)const{return l<a.l;}
};
set<Node> st;
set<Node>::iterator split(int pos)
{
    auto it=st.lower_bound(Node(pos));
    if (it!=st.end()&&it->l==pos) return it;
    --it;Node tmp=*it;st.erase(it);
    st.insert(Node(tmp.l,pos-1,tmp.val));
    return st.insert(Node(pos,tmp.r,tmp.val)).first;
}
void assign(int l,int r,int val)
{
    auto itr=split(r+1),itl=split(l);
    vector<int> ava;
    for(auto it=itl; it!=itr; ++it)
    	// printf("%lld %lld %lld %lld\n",it->l,it->r,it->val,val),
        update(1,n,it->l,it->r,1,abs(val-it->val));
    st.erase(itl,itr),st.insert(Node(l,r,val));
    return ;
}
signed main()
{
    n=read(),m=read();
    st.insert((Node){-1000000000,0,0});
    st.insert((Node){n+1,1000000000,0});
    for(int i=1; i<=n; ++i)
    	st.insert((Node){i,i,a[i]=i});
    for(int op,l,r; m--;)
    {
        op=read(),l=read(),r=read();
        if(op==1) assign(l,r,read());
        else printf("%lld\n",query(1,n,l,r,1));
    }
    return 0;
}