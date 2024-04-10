#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
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
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,q,m;
int f[314159];
int a[314159];
int b[314159];
int tot;
void adda(int i,int x)
{
	tot-=(a[i]==b[i]);
	a[i]+=x;if(a[i]>=m)a[i]-=m;
	tot+=(a[i]==b[i]);
}
void addb(int i,int x)
{
	tot-=(a[i]==b[i]);
	b[i]+=x;if(b[i]>=m)b[i]-=m;
	tot+=(a[i]==b[i]);
}
void suba(int i,int x)
{
	tot-=(a[i]==b[i]);
	a[i]-=x;if(a[i]<0)a[i]+=m;
	tot+=(a[i]==b[i]);
}
void subb(int i,int x)
{
	tot-=(a[i]==b[i]);
	b[i]-=x;if(b[i]<0)b[i]+=m;
	tot+=(a[i]==b[i]);
}
char c;
int l,r;
void init()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>q>>m;
	f[1]=f[2]=1;
	for(int i=3;i<=303030;++i)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=m) f[i]-=m;
	}
	rep1(i,n)
	{
		cin>>a[i];
	}
	for(int i=n;i>=3;--i)
	{
		a[i]-=a[i-1];
		if(a[i]<0)a[i]+=m;
		a[i]-=a[i-2];
		if(a[i]<0)a[i]+=m;
	}
	rep1(i,n)
	{
		cin>>b[i];
	}
	for(int i=n;i>=3;--i)
	{
		b[i]-=b[i-1];
		if(b[i]<0)b[i]+=m;
		b[i]-=b[i-2];
		if(b[i]<0)b[i]+=m;
	}
	rep1(i,n) if(a[i]==b[i]) ++tot;
}
mt19937_64 myrand(time(0));
string yes[8]={"YES","Yes","yES","yes","YEs","yEs","YeS","yeS"};
string no[4]={"NO","No","no","nO"};
void query()
{
	cin>>c>>l>>r;
	int cnt=0;
	/*
	if(l==r)
	{
		if(l==1)
		{
			if(c=='A')
			{
				adda(1,1);
				if(n>=3)suba(3,1);
			}
			else
			{
				addb(1,1);
				if(n>=3)subb(3,1);
			}
		}
		else
		{
			if(c=='A')
			{
				adda(l,1);
				if(l+1<=n)suba(l+1,1);
				if(l+2<=n)suba(l+2,1);
			}
			else
			{
				addb(l,1);
				if(l+1<=n)subb(l+1,1);
				if(l+2<=n)subb(l+2,1);
			}
		}
		if(tot==n)
		cout<<yes[myrand()&7]<<endl;
		else
		cout<<no[myrand()&3]<<endl;
		return ;
	}
	*/
	for(int i=l;i<=r&&i<=2;++i)
	{
		if(c=='A') adda(i,f[++cnt]);
		else addb(i,f[++cnt]);
	}
	if(l>=3)
	{
		if(c=='A') adda(l,1);
		else addb(l,1);
	}
	if(r>=2&&r<n)
	{
		if(c=='A') suba(r+1,f[r-l+2]);
		else subb(r+1,f[r-l+2]);
	}
	if(r>=1&&r<n-1)
	{
		if(c=='A') suba(r+2,f[r-l+1]);
		else subb(r+2,f[r-l+1]);
	}
	/*
	rep1(i,n)
	cout<<a[i]<<' ';
	cout<<endl;
	rep1(i,n)
	cout<<b[i]<<' ';
	cout<<endl;
	//*/
	if(tot==n)
	cout<<yes[myrand()&7]<<endl;
	else
	cout<<no[myrand()&3]<<endl;
}
int main()
{
	init();
	while(q--)
	query();
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/