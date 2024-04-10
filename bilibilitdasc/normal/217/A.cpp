#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
map< pair<int,int>,pair<int,int> > fat;
int x[105],y[105],n;
void add(pair<int,int> n)
{
	fat[n]=n;
}
pair<int,int> getf(pair<int,int> p)
{
	if(fat[p]==p)
	return p;
	return fat[p]=getf(fat[p]);
}
void con(pair<int,int> a,pair<int,int> b)
{
	fat[getf(a)]=getf(b);
}
int main()
{
	int ans=-1;
	cin>>n;
	rep(i,n)
	{
		pair<int,int> d;
		cin>>x[i]>>y[i];
		d.first=x[i],d.second=y[i];
		add(d);
		rep(j,i)
		{
			if(x[i]==x[j]||y[i]==y[j])
			con(d,make_pair(x[j],y[j]));
		}
	}
	rep(i,n)
	{
		if(fat[make_pair(x[i],y[i])]==make_pair(x[i],y[i]))
		ans++;
	}
	prt(ans);
	return 0;
}