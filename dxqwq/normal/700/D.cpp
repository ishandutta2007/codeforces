// Problem: CF700D Huffman Coding on Segment
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF700D
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Can you hear the crystal hissing in the heat?
// Can you see the crystal glaring on the beat?
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct query
{
	int l,r,id,pos;
	bool operator<(const query &lxl)const
	{return (pos<lxl.pos)||(pos==lxl.pos&&((pos&1)?r<lxl.r:r>lxl.r));}
}q[100003];
int a[100003],ans[100003],c[100003];
unordered_map<int,int> mp;
int tmp[2403];
const int S1=800,S2=1600;
inline int solve()
{
	int ans=0,lst=0;
	for(int i=1; i<=S1; ++i) tmp[i]=mp[i];
	for(int i=S1+1; i<=S2; ++i) tmp[i]=0;
	for(int i=1; i<=S1; ++i)
	{
		if(lst&&tmp[i]) ans+=i+lst,--tmp[i],++tmp[i+lst],lst=0;
		if(!tmp[i]) continue;
		ans+=i*(tmp[i]>>1)<<1,tmp[i<<1]+=tmp[i]>>1;
		if(tmp[i]&1) lst=i; 
	}
	priority_queue<int,vector<int>,greater<int>> t;
	for(int i=S1+1; i<=S2; ++i) 
		for(int j=1; j<=tmp[i]; ++j)
			t.push(i);
	for(auto i:mp) if(i.first>S1) 
		for(int j=1; j<=i.second; ++j) t.push(i.first);
	if(lst) t.push(lst);
	while(t.size()>1)
	{
		int x=t.top();
		t.pop(),x+=t.top(),t.pop(),ans+=x,t.push(x);
	}
	return ans;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	int m=read(),B=n/sqrt(m)+1;
	for(int i=1; i<=m; ++i)
		q[i].l=read(),q[i].r=read(),q[i].id=i,q[i].pos=q[i].l/B;
	sort(q+1,q+m+1),mp[0]=114514;
	for(int l=1,r=0,i=1; i<=m; ++i)
	{
		while(l>q[i].l) (!--mp[c[a[--l]]])&&(mp.erase(mp.find(c[a[l]])),0),++mp[++c[a[l]]];
		while(r<q[i].r) (!--mp[c[a[++r]]])&&(mp.erase(mp.find(c[a[r]])),0),++mp[++c[a[r]]];
		while(l<q[i].l) (!--mp[c[a[l]]])&&(mp.erase(mp.find(c[a[l]])),0),++mp[--c[a[l++]]];
		while(r>q[i].r) (!--mp[c[a[r]]])&&(mp.erase(mp.find(c[a[r]])),0),++mp[--c[a[r--]]];
		ans[q[i].id]=solve();
	}
	for(int i=1; i<=m; ++i) printf("%d\n",ans[i]);
	return 0;
}