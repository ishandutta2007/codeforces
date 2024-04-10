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
int n,cnt;
struct in
{
	int x,y;
}a[102];
bool avlb[102];//available
void dfs(int aa)
{
	avlb[aa]=1;
	rep(i,n)
	{
		if((a[i].x<a[aa].x&&a[aa].x<a[i].y||a[i].x<a[aa].y&&a[aa].y<a[i].y)&&!avlb[i])
		dfs(i);
	}
}
int main()
{
	cin>>n;
	rep(i,n)
	{
		int c,d,x;
		cin>>x>>c>>d;
		if(x==1)
		{
			a[cnt].x=c;
			a[cnt].y=d;
			cnt++;
		}
		else
		{
			c--;
			d--;
			fill(avlb,avlb+cnt,0);
			dfs(c);
			if(avlb[d])
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
	}
	return 0;
}
/**
not and or bitand bitor xor int long short signed unsigned float double using
char struct static class this return auto union enum extern register void volatile 
break sizeof asm bool catch const_cast delete dynamic_cast explicit export friend 
reinterpret_cast static_cast template throw try typeid typename virtual namespace 
typedef const constexpr true false if else mutable new operator private protected
for while do case goto default continue wchar_t switch inline static_assert public
/*
*/
/**
try again
virtual reality
do sth
best friend
this switch is not true 
have a break
now continue
return home
double kill
long long ago
in public or private
/*
*/