#include <bits/stdc++.h>
//on luogu
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=996996991;
const ll base1=997;
const ll mod2=998998943;
const ll base2=941;
//ios_base::sync_with_stdio(false);cin
char s[100005];
char t[100005];
char o[200005];
int l1,l2;
int z[200005];
int mxz[100005],idx[100005];
ll pw1[100005],pw2[100005];
ll hs1[100005],ht1[100005];
ll hs2[100005],ht2[100005];
void generate_hash(int l,char *s,ll *hs,ll mod,ll base)
{
	hs[0]=0;
	for(int i=1;i<=l;++i)
	{
		hs[i]=(hs[i-1]*base+s[i-1])%mod;
	}
}
ll myhash(ll*hs,ll*pw,ll md,int st,int ed)
{
	return (hs[ed]-hs[st]*pw[ed-st]%md+md)%md;
}
bool palin(int st,int ed)
{
	return myhash(hs1,pw1,mod1,st,ed+1)==myhash(ht1,pw1,mod1,l1-1-ed,l1-st)
	&&myhash(hs2,pw2,mod2,st,ed+1)==myhash(ht2,pw2,mod2,l1-1-ed,l1-st);
}
void calc_z()
{
	int l=0,r=0;
	for(int i=1;i<l2;++i)
	{
		if(i>r)
		{
			for(int j=i;;++j)
			{
				if(o[j]!=o[j-i])
				{
					z[i]=j-i;
					break;
				}
			}
		}
		else
		{
			if(z[i-l]<=r-i)
			{
				z[i]=z[i-l];
			}
			else
			{
				for(int j=r+1;;++j)
				{
					if(o[j]!=o[j-i])
					{
						z[i]=j-i;
						break;
					}
				}
			}
		}
		if(z[i]&&i+z[i]-1>r)
		{
			l=i;r=i+z[i]-1;
		}
	}
	mxz[1]=z[l1+1];
	idx[1]=l1+1;
	for(int i=l1+2;i<l2;++i)
	{
		if(z[i]>mxz[i-1-l1])
		{
			mxz[i-l1]=z[i];
			idx[i-l1]=i;
		}
		else
		{
			mxz[i-l1]=mxz[i-1-l1];
			idx[i-l1]=idx[i-1-l1];
		}
	}
}
void init()
{
	scanf("%s",s);
	strcpy(t,s);
	l1=strlen(s);
	reverse(t,t+l1);
	strcpy(o,t);
	o[l1]='$';
	l2=l1+1;
	strcpy(o+l2,s);
	l2+=l1;
	pw1[0]=1;for(int i=1;i<=100000;++i)pw1[i]=pw1[i-1]*base1%mod1;
	pw2[0]=1;for(int i=1;i<=100000;++i)pw2[i]=pw2[i-1]*base2%mod2;
	generate_hash(l1,s,hs1,mod1,base1);generate_hash(l1,s,hs2,mod2,base2);
	generate_hash(l1,t,ht1,mod1,base1);generate_hash(l1,t,ht2,mod2,base2);
	calc_z();
}
int maxlb,maxrb,maxlc,maxla,maxlen1,maxlen2,maxlen=-114514;
int curlb,currb,curlen;
void test(int midb)
{
	int l=0,r=min(midb+1,l1-midb),m;
	while(r-l>1)
	{
		m=(l+r)>>1;
		if(palin(midb-m,midb+m))
		{
			l=m;
		}
		else
		{
			r=m;
		}
	}
	curlb=midb-l;currb=midb+l;
	l=0;r=min(curlb,l1-1-currb)+1;
	while(r-l>1)
	{
		m=(l+r)>>1;
		int rb=curlb-m;
		if(mxz[rb+1]>=m)
		{
			l=m;
		}
		else
		{
			r=m;
		}
	}
	curlen=2*l+(currb-curlb+1);
	if(curlen>maxlen)
	{
		maxlen=curlen;
		maxlen1=currb-curlb+1;
		maxlb=curlb;
		maxrb=currb;
		maxla=idx[curlb-l+1]-l1-1;
		maxlc=l1-l;
		maxlen2=l;
	}
}
int main()
{
	init();
	for(int i=0;i<l1;++i)
	test(i);
	if(maxlen2)
	{
		printf("3\n%d %d\n%d %d\n%d %d\n",maxla+1,maxlen2,maxlb+1,maxlen1,maxlc+1,maxlen2);
	}
	else
	{
		printf("1\n%d %d\n",maxlb+1,maxlen1);
	}
	return 0;
}