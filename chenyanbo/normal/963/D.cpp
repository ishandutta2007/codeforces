#include<bits/stdc++.h>
#define N 100005
#define MO MO1
#define MO1 998244353
using namespace std;

int k,q,l,ll,LL,ma,ans2,ans,n,m,si,dd[N],ans1,po,p[N],c[N],r[N],sa[N],t[N],h[N],op[N];
char ss[N],s[N];

inline void SA()
{
	n=strlen(s+1);
	for(int i=1; i<=n; ++i)sa[i]=i,r[i]=s[i]-'a'+1;
	si=26;
	for(; po<n; si=po){
		po=0;
		for(int i=n-l+1; i<=n; ++i)p[++po]=i;
		for(int i=1; i<=n; ++i)if(sa[i]>l)p[++po]=sa[i]-l;
		memset(c,0,sizeof(c));
		for(int i=1; i<=n; ++i)++c[r[i]];
		for(int i=1; i<=si; ++i)c[i]+=c[i-1];
		for(int i=n; i; --i)sa[c[r[p[i]]]--]=p[i];
		
		po=0;
		for(int i=1; i<=n; ++i){
			t[sa[i]]= r[sa[i]]==r[sa[i-1]]&&r[sa[i]+l]==r[sa[i-1]+l] ? po : ++po; //++_po
		}

		memcpy(r,t,sizeof(t));
		l=!l?1:l<<1;
	}
}

inline int ch(int p)
{
	int pp=sa[p];
	int cc=(op[pp+m-1]-(long long)op[pp-1]*h[m]%MO+MO)%MO;
	if(cc==dd[m])return 1;
	return 0;
}

inline int ch1(int p)
{
	if(ch(p))return 0;
	int pp=sa[p],ns=m,l=1,r=m-1; //as
	
	while(l<=r){
		int mid=(l+r)>>1; //p-1  vv v u
		int cc=(op[pp+mid-1]-(long long)op[pp-1]*h[mid]%MO+MO)%MO;
		if(cc!=dd[mid]){
			ns=mid;
			r=mid-1;
		}else l=mid+1;
	}
	
	//\0// 0 //
//	if(s[pp+ns-1] == 0) return 0;
	if(s[pp+ns-1]<ss[ns])return 0;
	return 1;
}

inline int ch2(int p)
{
	if(ch(p))return 0;
	int pp=sa[p],ns=m,l=1,r=m-1;
	
	while(l<=r){
		int mid=(l+r)>>1; 
		int cc=(op[pp+mid-1]-(long long)op[pp-1]*h[mid]%MO+MO)%MO;
		if(cc!=dd[mid]){
			ns=mid;
			r=mid-1;
		}else l=mid+1;
	}

	if(s[pp+ns-1]<ss[ns])return 1;
	return 0;
}

int main()
{
	int l, r,mid;
	scanf("%s",s+1);
	SA();
	
	for(int i=1; i<=n; ++i)op[i]=((long long)op[i-1]*29+s[i]-'a'+1)%MO;	
	h[0]=1;for(int i=1; i<=n; ++i)h[i]=(long long)h[i-1]*29%MO;
	
	scanf("%d",&q);
	while(q--){
		scanf("%d",&k);
		scanf("%s",ss+1);
		m=strlen(ss+1);
		for(int i=1; i<=m; ++i){
			dd[i]=((long long)dd[i-1]*29 + ss[i]-'a'+1)%MO;  //s
		}
		
		l=1; r=n; ans1=n+1;
		while(l<=r){
			mid=(l+r)>>1;
			if(ch1(mid)){   //>
				ans1=mid;
				r=mid-1;
			}else l=mid+1;
		}
		
		l=1; r=n; ans2=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(ch2(mid)){   //mid < s  
				ans2=mid;
				l=mid+1;
			}else r=mid-1;
		}
		
		--ans1;
		++ans2;
		
		if(ans1-ans2+1<k){
			puts("-1");
			continue;
		}
		
		po=0;
		for(int i=ans2; i<=ans1; ++i)p[++po]=sa[i];
		sort(p+1,p+1+po);
		ma=p[k]-p[1];
		for(int i=k+1; i<=po; ++i)ma=min(ma,p[i]-p[i-k+1]); 
		printf("%d\n",ma+m);
	}
}
/*
abbb
1
1 ab
*/