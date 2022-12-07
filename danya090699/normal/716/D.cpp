#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#define int long long
using namespace std;
int n, m, l, s, t, bg=pow(10, 14), **dis;
vector <pair <int, int> > *sv, *sv2; 
void bway()
{
	set <pair <int, int> > q;
	for(int a=0; a<n; a++) dis[a][0]=bg;
	dis[s][0]=0;
	q.insert(make_pair(0, s));
	while(q.size()!=0)
	{
		int cv=(*q.begin()).second;
		q.erase(q.begin());
		for(int a=0; a<sv[cv].size(); a++)
		{
			int to=sv[cv][a].first, way=sv[cv][a].second;
			if(way!=bg)
			{
				if((dis[cv][0]+way)<dis[to][0])
				{
					q.erase(make_pair(dis[to][0], to));
					dis[to][0]=dis[cv][0]+way;
					dis[to][1]=cv;
					q.insert(make_pair(dis[to][0], to));
				}
			}
		}
	}
}
main()
{
	//ifstream in("input.txt");
	cin>>n>>m>>l>>s>>t;
	sv=new vector <pair <int, int> >[n], sv2=new vector <pair <int, int> >[n], dis=new int*[n];
	for(int a=0; a<n; a++) dis[a]=new int[2];
	for(int a=0; a<m; a++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		sv2[u].push_back(make_pair(v, w));
		sv2[v].push_back(make_pair(u, w));
		if(w==0) w=bg;
		sv[u].push_back(make_pair(v, w));
		sv[v].push_back(make_pair(u, w));
	}
	bway();
	if(dis[t][0]<l) cout<<"NO";
	else
	{
		for(int a=0; a<n; a++)
		{
			for(int b=0; b<sv[a].size(); b++) if(sv[a][b].second==bg) sv[a][b].second=1;
		}
		bway();
		if(dis[t][0]>l) cout<<"NO";
		else
		{
			cout<<"YES";
			for(int a=0; a<n; a++)
			{
				for(int b=0; b<sv2[a].size(); b++) if(sv2[a][b].second==0) sv[a][b].second=bg;
			}
			vector <int> wa;
			wa.push_back(t);
			int pre=t;
			while(pre!=s)
			{
				pre=dis[pre][1], wa.push_back(pre);
			}
			for(int a=0; a<(wa.size()-1); a++)
			{
				int st=wa[a], fi=wa[a+1];
				for(int b=0; b<sv[st].size(); b++) if((sv[st][b].first==fi)and(sv[st][b].second==bg)) sv[st][b].second=1;
				for(int b=0; b<sv[fi].size(); b++) if((sv[fi][b].first==st)and(sv[fi][b].second==bg)) sv[fi][b].second=1;
			}
			bway();
			bool fou=0;
			for(int a=0; a<(wa.size()-1); a++)
			{
				int st=wa[a], fi=wa[a+1];
				for(int b=0; b<sv[st].size(); b++)
				{
					if((sv2[st][b].first==fi)and(sv2[st][b].second==0))
					{
						int prbw=dis[t][0], c;
						sv[st][b].second=bg;
						for(c=0; c<sv[fi].size(); c++)
						{
							if(sv[fi][c].first==st)
							{
								sv[fi][c].second=bg;
								break;
							}
						}
						bway();
						if(dis[t][0]>l)
						{
							sv[st][b].second=1+(l-prbw);
							sv[fi][c].second=1+(l-prbw);
							fou=1;
							break;
						}
					}
				}
				if(fou) break;
			}
			for(int a=0; a<n; a++)
			{
				for(int b=0; b<sv[a].size(); b++)
				{
					if(a<sv[a][b].first) cout<<"\n"<<a<<" "<<sv[a][b].first<<" "<<sv[a][b].second;
				}
			}
		}
	}
}