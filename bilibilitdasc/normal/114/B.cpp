#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//cin
string c,d;
map<string,int> ind;
string a[18];
bool have[18][18];
int n,m;
int maxans;
vector<int> ans;
void valid(vector<int> v)
{
	rep(i,v.size()) rep(j,i)
	{
		if(have[v[i]][v[j]])
		return ;
	}
	if(v.size()>maxans)
	{
		maxans=v.size();
		ans=v;
	}
}
vector<int> tmp;
void isok(int a)
{
	tmp.clear();
	rep(i,n)
	{
		if((a>>i)&1)
		tmp.push_back(i);
	}
	valid(tmp);
}
vector<string> res;
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n)
	{
		cin>>a[i];
		ind[a[i]]=i;
	}
	rep(i,m)
	{
		cin>>c;
		cin>>d;
		//g(c);
		//g(d);
		int j=ind[c],k=ind[d];
		have[j][k]=have[k][j]=1;
	}
	
	rep(i,1<<n)
	{
		isok(i);
	}
	cout<<ans.size()<<endl;
	rep(i,ans.size())
	{
		res.pb(a[ans[i]]);
	}
	sort(res.begin(),res.end());
	rep(i,res.size())
	{
		cout<<res[i];
		cout<<endl;
	}
	cout<<endl;
	return 0;
	
	/*
	cout<<ind["a"]<<endl;
	cout<<ind["b"]<<endl;
	cout<<ind["c"]<<endl;
	cout<<ind["d"]<<endl;
	cout<<ind["e"]<<endl;
	cout<<ind["f"]<<endl;
	cout<<ind["g"]<<endl;
	cout<<ind["h"]<<endl;
	
	return 0;
	*/
}
/*
8 6
a
b
c
d
e
f
g
h
a b
b c
c d
d a
e f
g h

*/