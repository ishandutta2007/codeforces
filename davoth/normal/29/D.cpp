    #include<bits/stdc++.h>
    using namespace std;
    vector<int>e[303],ans;
    bool dfs(int x,int y,int last)
    {
    	if(x==y)return 1;
    	for(int i=0;i<e[x].size();i++)
    		if(e[x][i]!=last)
    			if(dfs(e[x][i],y,x))
    			{
    				ans.push_back(x);
    				return 1;
    			}
    	return 0;
    }
    int n,x,y;
    int main()
    {
    	cin>>n;
    	for(int i=0;i<n-1;i++)
    	{
    		cin>>x>>y;
    		e[x].push_back(y);
    		e[y].push_back(x);
    	}
    	ans.push_back(1);
    	int y=1;
    	while(cin>>x)
    	{
    		dfs(x,y,0);
    		y=x;
    	}
    	dfs(1,y,0);
    	if(ans.size()!=n*2-1)
    		cout<<-1;
    	else
    		for(int i=0;i<ans.size();i++)
    			cout<<ans[i]<<' ';
    }