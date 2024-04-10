#include<iostream>
#include<set>
using namespace std;
#define ll long long
set<int> ans;
ll n;
void dfs(ll x,int a,int b)
{
	if(x>n)
		return;
	ans.insert(x);
	if(x*10+a!=x)
		dfs(x*10+a,a,b);
	if(x*10+b!=x)
		dfs(x*10+b,a,b);
}
int main()
{
	cin>>n;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			dfs(0,i,j);
	cout<<ans.size()-1;//0 
	return 0;
}
/*1
10
*/
/*1
123
*/