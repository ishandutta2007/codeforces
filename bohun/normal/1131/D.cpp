	#include <bits/stdc++.h>
	#define ll long long 
	#define ld long double
	using namespace std;
	char s[1005][1005];
	int n,m;
	int hasz[1005],hh[1005];
	map < char , int > mapa;
	int mod=1e9+9;
	int p=29;
	vector < int > k[1005],w[1005];
	vector < int > v[100005],rev[100005];
	int color[100005];
	int cyc=0;
	int res[1000005];
	queue < int > q;
	int gruby[100005];
	int pp=29;
	int id[100005];
	bool odw[100005];
	int f(int x)
	{
		if(id[x]!=x)
			id[x]=f(id[x]);
		return id[x];
	}
	void onion(int x,int y)
	{
		if(f(x)==f(y))
			return ;
		id[f(x)]=f(y);
	}
	void dfs(int node)
	{
		color[node]=1;
		for(auto it: v[node])
		{
			if(color[it]==1)
				cyc=1;
			if(color[it]==0)
				{
					dfs(it);
				}
		}
		color[node]=2;
	}
	int main()
	{	
		cin>>n>>m;
		mapa['=']=1e9+7;
		mapa['>']=10009;
		mapa['<']=66666666;
		for(int i=1;n+m>=i;i++)
			id[i]=i;
		for(int i=1;n>=i;i++)
		{
			scanf("%s",s[i]+1);
			p=29;
			for(int j=1;m>=j;j++)
				{
					hasz[i]=((ll)mapa[s[i][j]]*p+hasz[i])%mod;
					p=((ll)p*pp)%mod;
				}
			for(int j=1;m>=j;j++)
				{
					if(s[i][j]=='=')
						{
							onion(i,j+n);
							k[j].push_back(i);
							w[i].push_back(j);
						}
				}
		}
		p=29;
		for(int j=1;m>=j;j++)
			{
				p=29;
				for(int i=1;n>=i;i++)
				{
					hh[j]=((ll)mapa[s[i][j]]*p+hh[j])%mod;
					p=(ll)p*pp%mod;
				}
			}
				
		for(int i=1;n>=i;i++)
			{
				if(w[i].size()==0)
					continue;
				int hi=hh[w[i][0]];
				for(auto it: w[i])
				{
					if(hh[it]!=hi)
						{
							cout<<"No";
							return 0;
						}
				}
			}
		for(int j=1;m>=j;j++)
			{
				if(k[j].size()==0)
					continue;
				int hi=hasz[k[j][0]];
				for(auto it: k[j])
				{
					if(hasz[it]!=hi)
						{
							cout<<"No";
							return 0;
						}
				}
			}
		for(int i=1;n>=i;i++)
			for(int j=1;m>=j;j++)
				{
					int x=f(i);
					int y=f(n+j);
					if(s[i][j]=='>')
						{
							v[x].push_back(y);
							rev[y].push_back(x);
						}
					else if(s[i][j]=='<')
						{
							v[y].push_back(x);
							rev[x].push_back(y);
						}
				}
		for(int i=1;n+m>=i;i++)
			if(color[i]==0)
				dfs(i);
		for(int i=1;n+m>=i;i++)
			gruby[i]=v[i].size();
		if(cyc==1)
		{
			cout<<"No";
			return 0;
		}		
		for(int i=1;n+m>=i;i++)
		{
			if(v[f(i)].size()==0)
				q.push(f(i));
		}
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			if(odw[node]==1)
				continue;
			odw[node]=1;
			int maxi=0;
			for(auto it: v[node])
			{
				maxi=max(maxi,res[it]);
			}
			res[node]=maxi+1;
			for(auto it: rev[node])
			{
				gruby[it]--;
				if(gruby[it]==0)
					q.push(it);
			}
		}
		cout<<"Yes\n";
		for(int i=1;n>=i;i++)
			cout<<res[f(i)]<<" ";
		cout<<endl;
		for(int i=n+1;n+m>=i;i++)
			cout<<res[f(i)]<<" ";
		return 0;	
	}