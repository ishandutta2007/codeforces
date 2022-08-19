#include <iostream>
#include <vector>
using namespace std;
int x[100],y[100];
vector <int> nt[100];
bool v[100];
void dfs(int ns)
{
	v[ns]=true;
	for(int k=0;k<(int)nt[ns].size();k++)
	if(!v[nt[ns][k]])dfs(nt[ns][k]);
}
int main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		for(int j=0;j<i;j++)
		if(x[i]==x[j]||y[i]==y[j])
		{
			nt[i].push_back(j);
			nt[j].push_back(i);
		}
	}
	for(int k=0;k<n;k++)
	if(!v[k])
	{
		dfs(k);
		cnt++;
	}
	cnt--;
	cout<<cnt;
	return 0;
}