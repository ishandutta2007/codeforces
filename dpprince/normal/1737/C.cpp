// Author: Little09
// Problem: C. Ela and Crickets
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 


void work()
{
	cin >> n;
	int x=0,y=0;
	int flag=0,X,Y;
	for (int i=1;i<=3;i++)
	{
		int a,b;
		cin >> a >> b;
		if (a==1&&b==1) flag=1,X=1,Y=1;
		else if (a==1&&b==n) flag=2,X=1,Y=n;
		else if (a==n&&b==1) flag=3,X=n,Y=1;
		else if (a==n&&b==n) flag=4,X=n,Y=n;
		x^=a,y^=b;
	}
	int s,t;
	cin >> s >> t;
	if (flag==0||(flag!=0&&abs(x-X)+abs(y-Y)!=2))
	{
		if (s%2==x%2&&y%2==t%2) printNO;
		else printYES;	
	}
	else 
	{
		if (s==X||t==Y)printYES;
		else printNO;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}