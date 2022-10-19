#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n;
char a[200005];
char b[200005];
char T[200005];
int reva,revb;
bool Same;
int merge_sort(char *s,int l,int r)
{
	if(l==r)
	{
		return 0;
	}
	int m=(l+r)>>1;
	int res=merge_sort(s,l,m);
	res+=merge_sort(s,m+1,r);
	int L=l,R=m+1,I=l;
	while(L<=m&&R<=r)
	{
		if(s[L]>s[R])
		{
			res+=m-L+1;
			T[I++]=s[R++];
		}
		else if(s[R]>s[L])
		{
			T[I++]=s[L++];
		}
		else
		{
			T[I++]=s[L++];
		}
	}
	while(L<=m)
	{
		//res+=R-m;
		T[I++]=s[L++];
	}
	while(R<=r)
	{
		res+=m-L+1;
		T[I++]=s[R++];
	}
	for(int i=l;i<=r;++i)
	s[i]=T[i];
	return res;
}
void Q()
{
	scanf("%d%s%s",&n,a,b);
	reva=merge_sort(a,0,n-1);
	revb=merge_sort(b,0,n-1);
	Same=0;
	for(int i=1;i<n;++i) if(a[i]==a[i-1]) Same=1;
	//cout<<n<<' '<<reva<<' '<<revb<<endl;
	if(strcmp(a,b)!=0)
	{
		printf("NO\n");
		return;
	}
	if(Same)
	{
		printf("YES\n");
		return;
	}
	if((reva^revb)&1)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
}
char s[6]="dcba";
int main()
{
	scanf("%d",&t);
	while(t--)
	Q();
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