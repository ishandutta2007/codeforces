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
struct ii
{
	int cnt,al;
}lo[35];
int n,m,i,j,s,ans;
string st;
bool del[35];
bool cmp(ii x,ii y)
{
	return x.cnt<y.cnt;
}
int main()
{
	cin>>st>>m;
	for (i=0;i<st.length();i++) lo[st[i]-'a'+1].cnt++;
	for (i=1;i<=26;i++) 
	{
		lo[i].al=i;
		if (lo[i].cnt) ans++;
	}
	sort(lo+1,lo+26+1,cmp);
	i=1;
	while (!lo[i].cnt) i++;
	for (;i<=26&&m>=lo[i].cnt;i++)
	{
		del[lo[i].al]=1;
		m-=lo[i].cnt;
		ans--;
	}
	cout<<ans<<endl;
	for (i=0;i<st.length();i++)
	{
		if (!del[st[i]-'a'+1]) cout<<st[i];
	}
	return 0;
}