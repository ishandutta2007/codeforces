#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void print(long long x) {
    if(x>9) print(x/10);
    *O++=x%10+'0';
}
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
//unordered_map<long long,int> mp;
//unordered map is rubbish!
gp_hash_table<long long,int> mp; 
long long sum[100003],ans[100003];
int t[100003];
struct node
{
	int l,r,bl,id;
	bool operator<(const node&t)const{return bl<t.bl||(bl==t.bl&&r<t.r);}
}q[100003];
int n=read();
long long k=read();
signed main()
{	
	for(int i=1; i<=n; ++i) t[i]=read();
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+read()*(t[i]==1?1:-1);
	int m=read(),B=400;
	for(int i=1; i<=m; ++i) q[i].l=read()-1,q[i].r=read(),q[i].bl=q[i].l/B,q[i].id=i;
	sort(q+1,q+m+1);
	long long cur=0;	
	for(int i=1,l=1,r=0; i<=m; ++i)
	{
		while(r<q[i].r) cur+=mp[sum[++r]-k],++mp[sum[r]];
		while(l>q[i].l) cur+=mp[sum[--l]+k],++mp[sum[l]];
		while(r>q[i].r) --mp[sum[r]],cur-=mp[sum[r--]-k];
		while(l<q[i].l) --mp[sum[l]],cur-=mp[sum[l++]+k];
		ans[q[i].id]=cur;
	}
	for(int i=1; i<=m; ++i) print(ans[i]),*O++='\n';
	fwrite(obuf,O-obuf,1,stdout);
	return 0;
}