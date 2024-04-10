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
int n,x,y,i,j,bx,by,ma[15],ce;
char ch,ms[15];
vector<pair<int,int>/**/> rc[5];
bool check(vector<pair<int,int>/**/> v,int x,int mask)
{
	int p=lower_bound(v.begin(),v.end(),make_pair(x,0))-v.begin();
	//if (v.size()==2) cerr<<(v[p].second)<<endl;
	if (p&&((1<<v[p-1].second)&mask)) return 1;
	if (p<v.size()&&((1<<v[p].second)&mask)) return 1;
	return 0;
}
int main()
{
	cin>>n>>x>>y;
	ma[1]=ma[2]=ma[5]=ma[6]=1<<30;
	ma[3]=ma[4]=ma[7]=ma[8]=-1<<30;
	for (i=1;i<=n;i++)
	{
		scanf(" %c%d%d",&ch,&bx,&by);
		if (ch=='Q') ce=2;
		if (ch=='R') ce=1;
		if (ch=='B') ce=0; 
		if (bx==x)
		{
			rc[1].push_back(make_pair(by,ce));
		}
		if (by==y)
		{
			rc[2].push_back(make_pair(bx,ce));
		}
		if (bx+by==x+y)
		{
			rc[3].push_back(make_pair(by,ce));
		}
		if (bx-by==x-y)
		{
			rc[4].push_back(make_pair(by,ce));
		}
	}
	for (i=1;i<=4;i++) sort(rc[i].begin(),rc[i].end());
	/*cerr<<rc[1].size()<<endl;
	cerr<<rc[2].size()<<endl;
	cerr<<rc[3].size()<<endl;
	cerr<<rc[4].size()<<endl;*/
	if (check(rc[1],y,6)||check(rc[2],x,6)||check(rc[3],y,5)||check(rc[4],y,5)) cout<<"YES";
		else cout<<"NO";
	return 0;
}