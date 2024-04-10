#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,k,l,fa[105],x,y;
vector<int> team[3];
pair<int,vector<int>/**/> nteam[105];
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		fa[find(x)]=find(y);
	}
	for (i=1;i<=n;i++)
	{
		nteam[find(i)].second.push_back(i);
		nteam[find(i)].first++;
	}
	sort(nteam+1,nteam+n+1);
	for (i=1;!nteam[i].first;i++);
	for (l=i;l<=n;l++)
	{
		if (nteam[l].first>3)
		{
			cout<<-1;
			return 0;
		}
	}
	for (j=i;nteam[j].first==1;j++);
	for (k=j;nteam[k].first==2;k++);
	if (j-i!=k-j) 
	{
		if (j-i>k-j&&!((j-i-(k-j))%3))
		{
			for (l=0;j+l<k;l++) cout<<nteam[i+l].second[0]<<' '<<nteam[j+l].second[0]<<' '<<nteam[j+l].second[1]<<endl;
			for (;i+l<j;l+=3) cout<<nteam[i+l].second[0]<<' '<<nteam[i+l+1].second[0]<<' '<<nteam[i+l+2].second[0]<<endl;
			for (l=k;l<=n;l++) cout<<nteam[l].second[0]<<' '<<nteam[l].second[1]<<' '<<nteam[l].second[2]<<endl;
		}
		else cout<<-1;
		return 0;
	}
	for (l=0;i+l<j;l++) cout<<nteam[i+l].second[0]<<' '<<nteam[j+l].second[0]<<' '<<nteam[j+l].second[1]<<endl;
	for (l=k;l<=n;l++) cout<<nteam[l].second[0]<<' '<<nteam[l].second[1]<<' '<<nteam[l].second[2]<<endl;
	return 0;
}