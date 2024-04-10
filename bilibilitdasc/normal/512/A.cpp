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
int n,tb[27],t;
pair<int,int> te[27];//t,char
str name[105];
vector <int> v[27];// 
bool vis[27];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.first<b.first;
}
int sub(str a,str b)//aabc aab=1  ab abbh=-1 abc abd=1;
{
	if(a.size()==b.size())
	return 0;
	if(a.size()>b.size())
	{
		return a.substr(0,b.size())==b?1:0;
	}
	else
	{
		return b.substr(0,a.size())==a?-1:0;
	}
}
void dfs(int a)
{
	tb[a]=++t;
	rep(i,v[a].size())
	{
		if(tb[v[a][i]]==0)
		dfs(v[a][i]);
	}
	te[a].first=++t;
	te[a].second=a;
}
int main()
{
	cin>>n;
	rep(i,n)
	{
		cin>>name[i];
		if(i)
		{
			if(name[i]==name[i-1]) continue;
			rep(j,i)
			{
				if(sub(name[i],name[j])==-1)
				{
					cout<<"Impossible\n";
					return 0;
				}
			}
			rep(j,min(name[i].size(),name[i-1].size()))
			{
				if(name[i][j]!=name[i-1][j])
				{
					v[name[i][j]-'a'].pb(name[i-1][j]-'a');
					break;
				}
			}
		}
	}
	/*
	rep(i,26) 
	{
		printf("v[%c]:",i+'a');
		rep(j,v[i].size())
		{
			printf("%c ",v[i][j]+'a');
		}
		printf("\n");
	}
	*/
	rep(i,26)
	{
		if(tb[i]) continue;
		dfs(i);
	}
	rep(i,26)
	rep(j,v[i].size())
	{
		if(te[i]<te[v[i][j]])
		{ 
			cout<<"Impossible\n";
			return 0;
		}
	}
	sort(te,te+26,cmp);
	rep(i,26) cout<<(char)(te[i].second+'a');
	cout<<endl;
	return 0;
}