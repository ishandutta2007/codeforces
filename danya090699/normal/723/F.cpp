#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, m, s, t, ds, dt, s_t=0, onlys=0, onlyt=0, both=0, none=0;
	cin>>n>>m;
	vector <int> sv[n];
	vector <int*> com, ans;
	int us[n];
	for(int a=0; a<n; a++) us[a]=0;
	for(int a=0; a<m; a++)
	{
		int u, v;
		cin>>u>>v;
		u--, v--;
		sv[u].push_back(v), sv[v].push_back(u);
	}
	cin>>s>>t>>ds>>dt;
	s--, t--;
	for(int a=0; a<n; a++)
	{
		if(us[a]==0)
		{
			us[a]=1;
			if(a==s)
			{
				for(int b=0; b<sv[s].size(); b++) if(sv[s][b]==t) s_t=1;
			}
			else if(a!=t)
			{
				com.push_back(new int[2]);
				com.back()[0]=-1, com.back()[1]=-1;
				vector <int> ver;
				ver.push_back(a);
				for(int b=0; b<ver.size(); b++)
				{
					int cv=ver[b];
					for(int c=0; c<sv[cv].size(); c++)
					{
						int ne=sv[cv][c];
						if(ne==s) com.back()[0]=cv;
						else if(ne==t) com.back()[1]=cv;
						else
						{
							if(us[ne]==0)
							{
								ans.push_back(new int[2]);
								ans.back()[0]=cv, ans.back()[1]=ne;
								ver.push_back(ne);
								us[ne]=1;
							}
						}
					}
				}
				if((com.back()[0]!=-1)and(com.back()[1]==-1)) onlys++;
				if((com.back()[0]==-1)and(com.back()[1]!=-1)) onlyt++;
				if((com.back()[0]!=-1)and(com.back()[1]!=-1)) both++;
				if((com.back()[0]==-1)and(com.back()[1]==-1)) none++;
			}
		}
	}
	if((none==0)and(onlys<ds)and(onlyt<dt))
	{
		ds-=onlys, dt-=onlyt;
		int pos=1, conn=0;
		if(both==0)
		{
			if(s_t==0) pos=0;
			else
			{
				ans.push_back(new int[2]);
				ans.back()[0]=s, ans.back()[1]=t;
				ds--, dt--;
			}
		}
		else
		{
			if(both+1>ds+dt) pos=0;
		}
		if(pos)
		{
			cout<<"Yes"<<"\n";
			for(int a=0; a<com.size(); a++)
			{
				if((com[a][0]!=-1)and(com[a][1]!=-1))
				{
					if(conn)
					{
						if(ds!=0)
						{
							ans.push_back(new int[2]);
							ans.back()[0]=com[a][0], ans.back()[1]=s;
							ds--;
						}
						else
						{
							ans.push_back(new int[2]);
							ans.back()[0]=com[a][1], ans.back()[1]=t;
							dt--;
						}
					}
					else
					{
						ans.push_back(new int[2]);
						ans.back()[0]=com[a][0], ans.back()[1]=s;
						ans.push_back(new int[2]);
						ans.back()[0]=com[a][1], ans.back()[1]=t;
						ds--, dt--, conn=1;
					}
				}
				else if((com[a][0]!=-1)and(com[a][1]==-1))
				{
					ans.push_back(new int[2]);
					ans.back()[0]=com[a][0], ans.back()[1]=s;
				}
				else
				{
					ans.push_back(new int[2]);
					ans.back()[0]=com[a][1], ans.back()[1]=t;
				}
			}
			for(int a=0; a<ans.size(); a++) cout<<ans[a][0]+1<<" "<<ans[a][1]+1<<"\n";
		}
		else cout<<"No";
	}
	else cout<<"No";
}