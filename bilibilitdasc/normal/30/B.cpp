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
int dd,mm,yy,a[3];
int dt[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
bool valid1(int d,int m,int y)
{
	if(!(1<=m&&m<=12)) return 0;
	if(m!=2) return d<=dt[m];
	if((y&3)) return d<=28;
	return d<=29;
}
bool valid2(int d,int m,int y)
{
	if(yy-y>18) return 1;if(yy-y<18) return 0;
	if(mm>m) return 1;
	return dd>=d;
}
int main()
{
	scanf("%02d.%02d.%02d\n%02d.%02d.%02d",&dd,&mm,&yy,a,a+1,a+2);
	sort(a,a+3);
	do
	{
		//g(a[0]);g(a[1]);g(a[2]);
		if(valid1(a[0],a[1],a[2])&&valid2(a[0],a[1],a[2]))
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	while(nextp(a,a+3));
	cout<<"NO"<<endl;
	return 0;
}