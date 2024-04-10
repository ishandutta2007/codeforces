#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> *sv, co2;
int n, m, k, *co, *us, ans=0;
void rec(int nu)
{
	us[nu]=1;
	co2.push_back(co[nu]);
	for(int a=0; a<sv[nu].size(); a++)
	{
		int ne=sv[nu][a];
		if(us[ne]==0) rec(ne);
	}
}
bool comp(int a, int b){return (a<b);}
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin>>n>>m>>k;
	co=new int[n], us=new int[n];
	for(int a=0; a<n; a++) cin>>co[a];
	for(int a=0; a<n; a++) us[a]=0;
	sv=new vector <int> [n];
	for(int a=0; a<m; a++)
	{
		int u, v;
		cin>>u>>v;
		u--, v--;
		sv[u].push_back(v), sv[v].push_back(u);
	}
	for(int a=0; a<n; a++)
	{
		if(us[a]==0)
		{
			rec(a);
			int yk=0, bq=0;
			sort(co2.begin(), co2.end(), comp);
			while(yk<co2.size())
			{
				int cuco=co2[yk], q=0;
				while(yk<co2.size())
				{
					if(co2[yk]==cuco)
					{
						q++, yk++;
					}
					else break;
				}
				if(q>bq) bq=q;
			}
			ans+=co2.size()-bq;
			co2.clear();
		}
	}
	cout<<ans;
}