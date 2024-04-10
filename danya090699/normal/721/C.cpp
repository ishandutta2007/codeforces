#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int*> *sv;
vector <int> tout;
bool *us;
void rec(int nu)
{
	us[nu]=1;
	for(int a=0; a<sv[nu].size(); a++) if(us[sv[nu][a][0]]==0) rec(sv[nu][a][0]);
	tout.push_back(nu);
}
main()
{
	ifstream in("input.txt");
	int n, m, t, bg=2000000000;
	cin>>n>>m>>t;
	sv=new vector <int*>[n];
	us=new bool[n];
	for(int a=0; a<m; a++)
	{
		int u, v, t;
		cin>>u>>v>>t;
		u--, v--;
		sv[u].push_back(new int[2]);
		sv[u].back()[0]=v, sv[u].back()[1]=t;
	}
	for(int a=0; a<n; a++) us[a]=0;
	for(int a=0; a<n; a++)
	{
		if(us[a]==0) rec(a);
	}
	reverse(tout.begin(), tout.end());
	int sos[n][n][2], num[n];
	for(int a=0; a<n; a++) num[tout[a]]=a;
	for(int a=0; a<n; a++) for(int b=0; b<n; b++) sos[a][b][0]=bg;
	int yk=0;
	for(int a=0; a<n-1; a++)
	{
		int ve=tout[a];
		if(ve==0) sos[a][0][0]=0;
		for(int b=0; b<n; b++)
		{
			if(sos[a][b][0]!=bg)
			{
				for(int c=0; c<sv[ve].size(); c++)
				{
					int dis=sv[ve][c][1], snu=num[sv[ve][c][0]];
					if(sos[a][b][0]+dis<sos[snu][b+1][0])
					{
						sos[snu][b+1][0]=sos[a][b][0]+dis;
						sos[snu][b+1][1]=a;
					}
				}
			}
		}
	}
	int snu=num[n-1], q;
	for(int a=n-1; a>=0; a--)
	{
		if(sos[snu][a][0]<=t)
		{
			q=a;
			break;
		}
	}
	cout<<q+1<<"\n";
	vector <int> ans;
	while(snu!=num[0])
	{
		ans.push_back(tout[snu]);
		snu=sos[snu][q][1];
		q--;
	}
	ans.push_back(0);
	reverse(ans.begin(), ans.end());
	for(int a=0; a<ans.size(); a++) cout<<ans[a]+1<<" ";
}