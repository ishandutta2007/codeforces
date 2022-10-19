#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
char s[266666];
int k,t,l,e,j,L;
char c;
int p[266666];
void solve()
{
	scanf("%d %c",&j,&c);
	//printf("c='%c'=%d ",c,c);
	j=L-j;
	s[j]=c;
	//printf("%s\n",s+1);
	while(j)
	{
		if(j>=e) p[j]=(s[j]=='?')?2:1;
		else
		{
			if(s[j]=='?') p[j]=p[j<<1]+p[(j<<1)+1];
			else if(s[j]=='0') p[j]=p[(j<<1)+1];
			else p[j]=p[j<<1];
		}
		j>>=1;
	}
	//rep1(i,l) printf("p[%d]=%d\n",i,p[i]);
	printf("%d\n",p[1]);
}
int main()
{
	scanf("%d%s",&k,s+1);L=(1<<k);l=L-1;e=1<<(k-1);
	reverse(s+1,s+l+1);
	//printf("\"%s\"=s,%d=l\n",s+1,l);
	per1(i,l)
	{
		if(i>=e)
		{
			p[i]=(s[i]=='?')?2:1;
		}
		else
		{
			if(s[i]=='?') p[i]=p[i<<1]+p[(i<<1)+1];
			else if(s[i]=='0') p[i]=p[(i<<1)+1];
			else p[i]=p[i<<1];
		}
		//printf("p[%d]=%d\n",i,p[i]);
	}
	scanf("%d",&t);
	while(t--)
	solve();
	return 0;
}