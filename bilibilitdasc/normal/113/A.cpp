#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod1=998244353;
string buf;
vector <string> a;
vector <int> b;
string ending[3][2]={{"lios","liala"},{"etr","etra"},{"initis","inites"}};
void out(string str)
{
	prt(str);
	exit(0);
}
int tp(string str)
{
	rep(i,3)
	rep(j,2)
	if(str.size()>=ending[i][j].size()&&str.substr(str.size()-ending[i][j].size())==ending[i][j])
	return i*2+j;
	out("NO");
	return -1;
}
int main()
{
	while(cin>>buf) a.push_back(buf);
	rep(i,a.size()) b.push_back(tp(a[i]));
	if(b.size()==1)
	out("YES");
	int cnt=0;
	rep(i,b.size()-1)
	if((b[i]^b[i+1])&1) out("NO");
	rep(i,b.size())
	cnt+=(b[i]/2==1);
	if(cnt!=1)
	out("NO");
	rep(i,b.size()-1)
	if(b[i]>b[i+1])
	out("NO");
	out("YES");
	return 0;
}