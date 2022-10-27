# include <bits/stdc++.h>
using namespace std;
int ch[300010][2],p[300010],a[300010],s[300010],mx[300010],mn[300010],stk[300010];
set<int> st;
struct Seg
{
	int l,r;
	Seg(int _l=0,int _r=0):l(_l),r(_r){}
}b[300010];
bool cmpr(Seg a,Seg b){return a.r<b.r;}
bool cmpl(Seg a,Seg b){return a.l>b.l;}
void dfs(int u)
{
	if(a[u]) mx[u]=a[u],mn[u]=min(mn[u],a[u]);
	if(ch[u][0]) mn[ch[u][0]]=mn[u],dfs(ch[u][0]),mx[u]=max(mx[u],mx[ch[u][0]]);
	if(ch[u][1]) mn[ch[u][1]]=mn[u],dfs(ch[u][1]),mx[u]=max(mx[u],mx[ch[u][1]]);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,q,d,k=0,tp=0;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++) scanf("%d",&p[i]),ch[i][0]=ch[i][1]=0,mn[i]=1e9,mx[i]=-1e9;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),k+=(!a[i]);
		for(int i=1;i<=n;i++)
		{
			while(tp && p[stk[tp]]<p[i]) ch[i][0]=stk[tp],tp--;
			if(tp) ch[stk[tp]][1]=i;
			stk[++tp]=i;
		}
		for(int i=1;i<k;i++) scanf("%d",&s[i]);
		dfs(stk[1]);
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(a[i] && (a[i]<mx[i] || a[i]>mn[i])) flag=0;
			else if(!a[i] && mx[i]>mn[i]) flag=0;
		if(!flag)
		{
			while(q--) scanf("%*d"),puts("NO");
			continue;
		}
		k=0;
		for(int i=1;i<=n;i++)
			if(!a[i]) b[++k]=Seg(mx[i],mn[i]);
		int L=-1e9,R=1e9;
		st.clear();
		for(int i=1;i<k;i++) st.insert(s[i]);
		sort(b+1,b+k+1,cmpr);
		for(int i=1;i<=k;i++)
		{
			auto it=st.lower_bound(b[i].l);
			if(it==st.end() || *it>b[i].r)
				if(R<1e9){flag=0;break;}
				else R=b[i].r;
			else st.erase(it);
		}
		if(!flag)
		{
			while(q--) scanf("%*d"),puts("NO");
			continue;
		}
		st.clear();
		for(int i=1;i<k;i++) st.insert(s[i]);
		sort(b+1,b+k+1,cmpl);
		for(int i=1;i<=k;i++)
		{
			auto it=st.upper_bound(b[i].r);
			if(it==st.begin() || *prev(it)<b[i].l)
				if(L>-1e9){flag=0;break;}
				else L=b[i].l;
			else st.erase(prev(it));
		}
		if(!flag)
		{
			while(q--) scanf("%*d"),puts("NO");
			continue;
		}
		while(q--) scanf("%d",&d),puts(L<=d && d<=R?"YES":"NO");
	}
	return 0;
}