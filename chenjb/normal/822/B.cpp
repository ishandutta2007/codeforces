#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#define LL long long 
#define inf 1000000007
using namespace std;
int n,m;
char a[2001];
char b[2001];
int save[2001];
int judge(int start)
{
	int ans=0;
	for(int i=start;i<=start+n-1;i++)
		if (b[i]!=a[i-start])save[++ans]=i-start+1;
	return ans;
}
void work()
{
	int ans=2147483647;
	int tp;
	for(int i=0;i<=m-n;i++)
	{
		int tmp=judge(i);
		if (tmp>=ans)continue;
		ans=tmp;
		tp=i;
	}
	judge(tp);
	cout<<ans<<endl;
	if (ans==0)return;
	cout<<save[1];
	for(int i=2;i<=ans;i++)cout<<" "<<save[i];
	cout<<endl;
}
int main()
{

	cin>>n>>m;
	scanf("%s",a);
	scanf("%s",b);
	work();
	return 0;
}