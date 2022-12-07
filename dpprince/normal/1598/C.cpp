// By: Little09
// Problem: C. Delete Two Elements
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
ll a[N],n;

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
map<ll,ll>q;
map<ll,ll>id;
int TTT;
void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),q[a[i]]=0;
	sort(a+1,a+n+1);
	ll sum=0;
	for (int i=1;i<=n;i++) sum+=a[i];
	sum=sum+sum;
	if (sum%n!=0)
	{
		puts("0");
		return;
	}
	ll u=sum/n,ans=0;
	for (int i=1;i<=n;i++)
	{
		ll p=u-a[i];
		if (id[p]==TTT) ans+=q[p];
		q[a[i]]++;
		id[a[i]]=TTT;
	}
	cout << ans << endl;
	return;
}

int main()
{
	int tp=0,T;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		TTT++;
		work();
	}
	return 0;
}