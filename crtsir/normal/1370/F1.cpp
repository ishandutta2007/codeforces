#include<bits/stdc++.h>
using namespace std;
int T,n,res;
vector<int>v[1003],dep[1003],lastquery;
bool vis[1003];
bool check(int depth,int checker1)
{
	if(dep[depth].empty())return 0;
	cout<<"? "<<dep[depth].size();
	for(int i=0;i<dep[depth].size();i++)printf(" %d",dep[depth][i]+1);
	cout<<endl;
	int tmp,checker2;
	cin>>tmp>>checker2;
	if(checker1==checker2)
	{
		res=tmp;
		return 1;
	}
	else
		return 0;
}
void DFS(int x,int p,int dep)
{
	if(dep==0)
		lastquery.push_back(x);
	else
		for(int i=0;i<v[x].size();i++)
			if(v[x][i]!=p)
				DFS(v[x][i],x,dep+1);
}
void solve()
{
	cin>>n;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++)
	{
		v[i].clear();
		dep[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout<<"? "<<n;
	for(int i=0;i<n;i++)
		printf(" %d",i+1); 
	cout<<endl;
	int rt,len;
	cin>>rt>>len;
	rt--;
	queue<pair<int,int> >Q;
	Q.push(make_pair(rt,0));
	vis[rt]=1;
	dep[0].push_back(rt);
	while(!Q.empty())
	{
		int now=Q.front().first,lenn=Q.front().second;
		Q.pop();
		for(int i=0;i<v[now].size();i++)
			if(!vis[v[now][i]])
			{
				vis[v[now][i]]=1;
				Q.push(make_pair(v[now][i],lenn+1));
				dep[lenn+1].push_back(v[now][i]);
			}
	} 
	int left=(len-1)/2+1,right=len;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(check(middle,len))
			left=middle+1;
		else
			right=middle-1;
	}
	lastquery.clear();
	DFS(res-1,-1,-len);
	cout<<"? "<<lastquery.size();
	for(int i=0;i<lastquery.size();i++)
		cout<<' '<<lastquery[i]+1;
	cout<<endl;
	int res2,tmp;
	cin>>res2>>tmp;
	cout<<"! "<<res2<<' '<<res<<endl;
	string s;
	cin>>s;
	if(s=="Incorrect")
		exit(0);
}
int main(){
	cin>>T;
	while(T--)
	{
		solve();
	}
}