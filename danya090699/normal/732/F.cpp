#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct ver
{
	int us=0, tin, fup;
};
struct reb
{
	int to, dir=0, nu, bnu;
};
int n, m, time=0, cuq;
vector <reb> *sv;
ver *ve;
void bri(int nu, int pr)
{
	ve[nu].us=1;
	ve[nu].tin=time;
	ve[nu].fup=time;
	time++;
	for(int a=0; a<sv[nu].size(); a++)
	{
		int ne=sv[nu][a].to;
		if(ne!=pr)
		{
			if(ve[ne].us)
			{
				if(ve[ne].tin>ve[nu].tin) sv[nu][a].dir=2;
				else
				{
					sv[nu][a].dir=1;
					ve[nu].fup=min(ve[nu].fup, ve[ne].tin);
				}
			}
			else
			{
				bri(ne, nu);
				ve[nu].fup=min(ve[nu].fup, ve[ne].fup);
				if(ve[ne].fup<=ve[nu].tin)//  
				{
					sv[nu][a].dir=1;
					int bl=sv[nu][a].bnu;
					sv[ne][bl].dir=2;
				}
			}
		}
	}
}
void dfs(int nu)
{
	ve[nu].us=0;
	cuq++;
	for(int a=0; a<sv[nu].size(); a++)
	{
		int ne=sv[nu][a].to;
		if((ve[ne].us)and(sv[nu][a].dir!=0)) dfs(ne);
	}
}
void dfs2(int nu)
{
	ve[nu].us=1;
	for(int a=0; a<sv[nu].size(); a++)
	{
		int ne=sv[nu][a].to;
		if(ve[ne].us==0)
		{
			if(sv[nu][a].dir==0) sv[nu][a].dir=2;
			dfs2(ne);
		}
	}
}
int main()
{
	ifstream in("input.txt");
	scanf("%d%d", &n, &m);
	sv=new vector <reb>[n], ve=new ver[n];
	for(int a=0; a<m; a++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		reb r1, r2;
		r1.to=v, r1.nu=a, r1.bnu=sv[v].size();
		r2.to=u, r2.nu=a, r2.bnu=sv[u].size();
		sv[u].push_back(r1), sv[v].push_back(r2);
	}
	bri(0, -1);
	int beq=0, bea;
	for(int a=0; a<n; a++)
	{
		if(ve[a].us)
		{
			cuq=0;
			dfs(a);
			if(cuq>beq)
			{
				beq=cuq, bea=a;
			}
		}
	}
	dfs2(bea);
	int an[m][2];
	for(int a=0; a<n; a++)
	{
		for(int b=0; b<sv[a].size(); b++)
		{
			int nr=sv[a][b].nu, to=sv[a][b].to;
			if(sv[a][b].dir!=2)
			{
				an[nr][0]=a+1, an[nr][1]=to+1;
			}
		}
	}
	printf("%d\n", beq);
	for(int a=0; a<m; a++) printf("%d %d\n", an[a][0], an[a][1]);
}