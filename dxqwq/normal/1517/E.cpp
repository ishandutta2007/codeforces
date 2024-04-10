// Problem: E. Group Photo
// Contest: Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1517/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int n,s;
int pre1[200003],pre0[200003];
int a[200003];
int b[200003];
void bf()
{
	int S=1<<n;
	int ans=0;
	for(int i=0; i<S; ++i)
	{
		b[i]=S;
		bool f=1;
		int lst=0,llst=0;
		int SA=0,SB=0;int c=0;
		for(int j=0; j<n; ++j) if(i&(1<<j)) 
		{
			SA+=a[j+1];
			++c;
			if(c>=3)
			{
				f&=(j-lst>=lst-llst);
			}
			llst=lst,lst=j;
		}
		lst=0,llst=0;c=0;
		for(int j=0; j<n; ++j) if(!(i&(1<<j))) 
		{
			SB+=a[j+1];
			++c;
			if(c>=3)
			{
				f&=(j-lst<=lst-llst);
			}
			llst=lst,lst=j;
		}
		if(f&&(SA>SB)) ++ans;
	}
	printf("%lld\n",ans);
	return ;
}
signed main()
{
    for(int T=read();T--;)
    {
    	n=read(),s=0;
    	for(int i=1; i<=n; ++i) a[n+1-i]=read(),s+=a[n+1-i];
    	if(n<=6) 
    	{
    		bf();
    		continue;
    	} 
    	for(int i=1; i<=n; ++i)
    	{
    		// printf("%lld ",a[i]);
    		pre1[i]=pre1[i-1];
    		pre0[i]=pre0[i-1];
    		if(i&1) pre1[i]+=a[i];
    		else pre0[i]+=a[i];
    	}
    	// puts("");
    	s=(s+2)>>1;
    	int ans=0;
    	for(int i=n,t=0; i>=1; --i)
    	{
    		t+=a[i];
    		if(t>=s)
    		{
    			ans=i;
    			break;
    		}
    	}
    	// cout<<ans<<" QWQ"<<endl;
    	int S=a[n];
    	//case 1: PCCC PPPC
    	for(int i=2; i+2<=n; ++i)
		{
			S+=a[i];
			if(S>=s)
			{
				int A=(n-i)/2;
				ans+=A;
				continue;
			}
			int l=i+2,r=n-2,tgt=s-S,res=n;
			if(l>r) continue;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int G;
				if(i&1) G=pre1[mid]-pre1[i];
				else G=pre0[mid]-pre0[i];
				if(G>=tgt)
				{
					res=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			ans+=(n-res)/2;
		}  	
		// cout<<ans<<endl;
    	//case 2: CCCC PPPC
    	S=a[n];
    	for(int i=1; i+2<=n; ++i)
		{
			S+=a[i];
			if(S>=s)
			{
				int A=(n-i)/2;
				ans+=A;
				continue;
			}
			int l=i+2,r=n-2,tgt=s-S,res=n;
			if(l>r) continue;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int G;
				if(i&1) G=pre1[mid]-pre1[i];
				else G=pre0[mid]-pre0[i];
				if(G>=tgt)
				{
					res=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			ans+=(n-res)/2;
		}    	  	
		// cout<<ans<<endl;
    	//case 3: PCCC PPPP
    	S=0;
    	for(int i=2; i<=n; ++i)
		{
			S+=a[i];
			if(S>=s)
			{
				int A=(n+1-i)/2;
				ans+=A;
				continue;
			}
			int l=i+2,r=n-1,tgt=s-S,res=n+1;
			if(l>r) continue;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int G;
				if(i&1) G=pre1[mid]-pre1[i];
				else G=pre0[mid]-pre0[i];
				if(G>=tgt)
				{
					res=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			ans+=(n+1-res)/2;
		}    	
		// cout<<ans<<endl;	
    	//case 4: CCCC PPPP
    	S=0;
    	for(int i=1; i<=n; ++i)
		{
			S+=a[i];
			if(S>=s)
			{
				int A=(n+1-i)/2;
				ans+=A;
				continue;
			}
			int l=i+2,r=n-1,tgt=s-S,res=n+1;
			if(l>r) continue;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int G;
				if(i&1) G=pre1[mid]-pre1[i];
				else G=pre0[mid]-pre0[i];
				if(G>=tgt)
				{
					res=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			ans+=(n+1-res)/2;
		}    	
		// cout<<ans<<endl;
		ans%=998244353;
    	printf("%lld\n",ans);
    }
	return 0;
}
/*
PPPC
PPCC
PCCC
CCCC
 
PCPC
 
CPPC
 
CCPC
 
2229
*/