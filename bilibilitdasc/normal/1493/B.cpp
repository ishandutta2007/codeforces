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
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int h,m,hh,mm;
int a,b,c,d;
const int rev[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
bool chk()
{
	a=hh/10;b=hh%10;c=mm/10;d=mm%10;
	if(rev[a]==-1||rev[b]==-1||rev[c]==-1||rev[d]==-1) return 0;
	return rev[d]*10+rev[c]<h&&rev[b]*10+rev[a]<m;
}
void Q()
{
	scanf("%d%d%d:%d",&h,&m,&hh,&mm);
	while(!chk())
	{
		mm++;
		if(mm==m)
		{
			mm=0;
			hh++;
			if(hh==h)
			{
				hh=0;
			}
		}
	}
	printf("%02d:%02d\n",hh,mm);
 } 
int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	Q();
	return 0;
}
/*
6
24 60
12:21
24 60
23:59
90 80
52:26
1 100
00:01
10 10
04:04
24 60
22:59

*/