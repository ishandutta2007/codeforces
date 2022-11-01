#include <bits/stdc++.h>
using namespace std;
int dis[567][567];
vector<int>a[567];
vector<int>ans1;//Alex's route: n
vector<int>ans2;//Bob's route: 1
queue<int>q;

pair<int,int>p[567][567];
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dis[1][n]=1;
    q.push(1);
    q.push(n);
    int u,v;
    p[1][n]={0,0};
    while(!q.empty())
    {
        u=q.front();//Bob
		q.pop();
        v=q.front();//Alex
		q.pop();
        if(u==v) continue;
        for(auto e : a[u])
        {
            for(auto w : a[v])
            {
                if(dis[e][w]==0)
                {
                    dis[e][w] = dis[u][v] + 1;
                    q.push(e);
                    q.push(w);
                    p[e][w]={u,v};
                }
            }
        }
    }
    if(dis[n][1]==0)
    {
    	puts("-1");
    	exit(0);
	}
	
    u=n;
    v=1;
    
    while(u + v > 0)
    {
        ans1.push_back(u);
        ans2.push_back(v);
        x=p[u][v].first;
        v=p[u][v].second;
        u=x;
    }
    
    cout<<ans1.size()-1<<endl;
    for(int i=0;i<ans1.size();i++)
    {
    	cout<<ans2[i]<<' ';
	}
    cout<<endl;
    
    for(int i=0;i<ans1.size();i++)
    {
    	 cout<<ans1[i]<<' ';
	}
    return 0;
}