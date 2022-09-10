#include <bits/stdc++.h>

using namespace std;

int n, m ;
int dis[110000] ;
vector< pair<int,int> > mm[110000] ;
int mark[110000] ;
int minDis ;
vector<int> ans ;
vector<int> path ;
int after[110000] ;
int pre[110000] ;

void dfs(int id)
{
	minDis = min(minDis, dis[id]) ;
	mark[id] = 1 ;
	for(auto r: mm[id])
		if(mark[r.first]==0 && r.second==0)
			dfs(r.first) ;
}

int main(){
	
	memset(dis, 0xff, sizeof(dis)) ;
	memset(mark, 0, sizeof(mark)) ;
	
	cin >> n >> m ;
	
	for(int i=0;i<n;i++)
		mm[i].clear() ;
	
	for(int i=0;i<m;i++)
	{
		int a, b, p ;
		cin >> a >> b >> p ;
		mm[b].push_back({a,p}) ;
		mm[a].push_back({b,p}) ;
	}
	
	queue<pair<int,int> > bb ;
	bb.push({0,0}) ;
	dis[0] = 0 ;
	
	while(bb.size()>0)
	{
		auto p = bb.front() ;
		bb.pop() ;
		
		int id = p.first ;
		int dd = p.second+1 ;
		for(auto r: mm[id])
		{
			int nid = r.first ;
			if(dis[nid]==-1)
			{
				dis[nid] = dd ;
				bb.push({nid, dd}) ;
			}
		}
	}
	
	minDis = dis[n-1] ;
	dfs(n-1) ;
	
	set<int> group[2] ;
	int cur = 0, nxt = 1 ;
	
	for(int i=0;i<n;i++)
		if(mark[i]==1 && dis[i]==minDis)
			group[cur].insert(i) ;
	
	for(int d=minDis-1;d>=0;d--)
	{
		group[nxt].clear() ;
		
		int minPos = 9 ;
		
		for(auto st: group[cur])
			for(auto r: mm[st])
				if(dis[r.first]==d)
					minPos = min(minPos, r.second) ;
		
		for(auto st: group[cur])
			for(auto r: mm[st])
				if(dis[r.first]==d && r.second==minPos)
					group[nxt].insert(r.first) ;
		
		ans.push_back(minPos) ;
		
		swap(nxt, cur) ;
	}
	
	for(auto r: ans)
		cout << r ;
	if(ans.size()==0)
		cout << 0 ;
	cout << endl ;
	
	reverse(ans.begin(), ans.end()) ; 
	
	group[cur].clear() ;
	group[cur].insert(0) ;
	mark[0] = 0 ;
	memset(pre, 0xff, sizeof(pre)) ;
	
	for(int i=1;i<=minDis;i++)
	{
		group[nxt].clear() ;
		for(auto id: group[cur])
			for(auto r: mm[id])
				if(dis[r.first]==i && r.second==ans[i-1])
				{
					group[nxt].insert(r.first) ;
					pre[r.first] = id ;
					mark[r.first] = -i ;
				}
		swap(cur, nxt) ;
	}
	
	queue<int> q ;
	memset(after, 0xff, sizeof(after)) ;
	q.push(n-1) ;
	after[n-1] = -2 ;
	
	int mp = -1 ;
	
	for(;;)
	{
		int id = q.front() ;
		q.pop() ;
		
		if(mark[id]==-minDis)
		{
			mp = id ;
			break ;
		}
		
		for(auto r:mm[id])
			if(r.second==0 && after[r.first]==-1)
			{
				after[r.first] = id ;
				q.push(r.first) ;
			}
	}
	
	int tp = mp ;
	
	do
	{
		path.push_back(tp) ;
		tp = pre[tp] ;
	} while(tp>=0) ;
	
	reverse(path.begin(), path.end()) ;
	
	mp = after[mp] ;
	while(mp>=0)
	{
		path.push_back(mp) ;
		mp = after[mp] ;
	}
	
	cout << path.size() << endl ;
	cout << path[0] ;
	for(int i=1;i<path.size();i++)
		cout << " " << path[i] ;
	cout << endl ;

    return 0;
}