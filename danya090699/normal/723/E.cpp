#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int t, n, m, sv[200][200], us[200], inq[200];
vector <int*> sm[200], ans;
vector <int> nech, cycle;
void rec(int nu)
{
	us[nu]=1;
	if(inq[nu]%2==1) nech.push_back(nu);
	for(int a=0; a<n; a++)
	{
		if((sv[nu][a])and(us[a]==0)) rec(a);
	}
}
void euler(int nu)
{
	while(sm[nu].size()!=0)
	{
		int ne=sm[nu].back()[0], pos=sm[nu].back()[1];
		if(ne!=-1)
		{
			sm[ne][pos][0]=-1;
			sm[nu].pop_back();
			euler(ne);
		}
		else sm[nu].pop_back();
	}
	cycle.push_back(nu);
}
int main()
{
	ifstream in("input.txt");
	cin>>t;
	for(int a=0; a<t; a++)
	{
		cin>>n>>m;
		int che=n;
		for(int b=0; b<200; b++)
		{
			us[b]=0, inq[b]=0;
		}
		for(int b=0; b<200; b++) for(int c=0; c<200; c++) sv[b][c]=0;
		for(int b=0; b<m; b++)
		{
			int u, v;
			cin>>u>>v;
			u--, v--;
			sv[u][v]=1, sv[v][u]=1;
			inq[u]++, inq[v]++;
			sm[u].push_back(new int[2]), sm[v].push_back(new int[2]);
			sm[u].back()[0]=v, sm[u].back()[1]=sm[v].size()-1;
			sm[v].back()[0]=u, sm[v].back()[1]=sm[u].size()-1;
		}
		for(int b=0; b<n; b++)
		{
			if(us[b]==0)
			{
				rec(b);
				che-=nech.size();
				for(int c=0; c<nech.size(); c+=2)
				{
					int u=nech[c], v=nech[c+1];
					sm[u].push_back(new int[2]), sm[v].push_back(new int[2]);
					sm[u].back()[0]=v, sm[u].back()[1]=sm[v].size()-1;
					sm[v].back()[0]=u, sm[v].back()[1]=sm[u].size()-1;
				}
				euler(b);
				for(int c=0; c<(cycle.size()-1); c++)
				{
					int u=cycle[c], v=cycle[c+1];
					if(sv[u][v])
					{
						sv[u][v]--, sv[v][u]--;
						ans.push_back(new int[2]);
						ans.back()[0]=u, ans.back()[1]=v;
					}
				}
				nech.clear(), cycle.clear();
			}
		}
		cout<<che<<"\n";
		while(ans.size()!=0)
		{
			cout<<ans.back()[0]+1<<" "<<ans.back()[1]+1<<"\n";
			delete [] ans.back();
			ans.pop_back();
		}
	}
}