#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
string st;
int n,m,i,j;
char up;
bool bo=0;
void dfs(int x)
{
	if (x<0) return;
	int i;
	for (i=st[x]+1;i<=up;i++)
	{
		if ((x&&st[x-1]==i)||(x>1&&st[x-2]==i)) continue;
		st[x]=i;
		bo=1;
		return;
	}
	dfs(x-1);
	if (!bo) return;
	for (i='a';i<=up;i++)
	{
		if ((x&&st[x-1]==i)||(x>1&&st[x-2]==i)) continue;
		st[x]=i;
		return;
	}
	bo=0;
}
int main()
{
	cin>>n>>m;
	up='a'+m-1;
	cin>>st;
	dfs(st.length()-1);
	if (bo) cout<<st;
		else cout<<"NO";
	return 0;
}