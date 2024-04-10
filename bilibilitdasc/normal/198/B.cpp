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
str l,r;
int d[2][100005];
queue<int> q;
int main()
{
	int n,k;
	cin>>n>>k>>l>>r;
	rep(i,2) rep(j,n) d[i][j]=2e9;
	d[0][0]=0;
	q.push(0);q.push(0);
	while(!q.empty())
	{
		int sd=q.front();q.pop();
		int h=q.front();q.pop();
		int t=d[sd][h];
		if(h+k>=n)
		{
			cout<<"YES\n";
			return 0;
		}
		if((sd==0&&l[h+1]=='-')||(sd==1&&r[h+1]=='-'))
		if(d[sd][h+1]==2e9)
		{
			d[sd][h+1]=t+1;
			q.push(sd);q.push(h+1);
		}
		if((h-1>=t+1)&&((sd==0&&l[h-1]=='-')||(sd==1&&r[h-1]=='-')))
		if(d[sd][h-1]==2e9)
		{
			d[sd][h-1]=t+1;
			q.push(sd);q.push(h-1);
		}
		if((sd==0&&r[h+k]=='-')||(sd==1&&l[h+k]=='-'))
		if(d[!sd][h+k]==2e9)
		{
			d[!sd][h+k]=t+1;
			q.push(!sd);q.push(h+k);
		}
	}
	cout<<"NO\n";
	return 0;
}
/*
6 2
-XXX-X
XX-XXX
*/