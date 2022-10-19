#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=200005;
int n,m;
char s[N],t[N];
int lind,rind;
int mn[N],mx[N];
int maxval(int i)//i&i+1width
{
	return mx[i+1]-mn[i];
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	int mxval=0;
	for(int i=0,ind=0;i<n;i++)
	{
		if(s[i]==t[ind])
		{
			mn[ind]=i;
			ind++;
		}
	}
	for(int i=n-1,ind=m-1;i>=0;i--)
	{
		if(s[i]==t[ind])
		{
			mx[ind]=i;
			ind--;
		}
	}
	for(int i=0;i<m-1;i++)
	{
		mxval=max(mxval,maxval(i));
	}
	cout<<mxval<<endl;
	return 0;
}