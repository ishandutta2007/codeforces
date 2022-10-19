#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n;
map<string,int> sc;//name to score
vector<string> na;
int getsc(int p,int m,int a,int b,int c,int d,int e)
{
	return a+b+c+d+e+100*p-50*m;
}
void IN()
{
	string h;
	int a,b,c,d,e,f,g;
	cin>>h>>a>>b>>c>>d>>e>>f>>g;
	na.push_back(h);
	sc[h]=getsc(a,b,c,d,e,f,g);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) IN();
	string l="";
	int mxsc=-2505;
	for(int i=0;i<na.size();i++)
	{
		if(sc[na[i]]>mxsc)
		{
			mxsc=sc[na[i]];
			l=na[i];
		}
		//cout<<na[i]<<'-'<<sc[na[i]]<<endl;
	}
	cout<<l<<endl;
	return 0;
}
/*
5
Petr 3 1 490 920 1000 1200 0
tourist 2 0 490 950 1100 1400 0
Egor 7 0 480 900 950 0 1000
c00lH4x0R 0 10 150 0 0 0 0
some_paiticipant 2 1 450 720 900 0 0


3
No 1 0 0 0 0 0 0
Yes 2 1 0 0 0 0 0
NO 3 5 0 0 0 0 0

*/