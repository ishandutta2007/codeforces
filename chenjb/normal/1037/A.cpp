#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int main()
{
	long long  n;
	cin>>n;
	int cnt=0;
	long long p=1;
	while (1)
	{
		cnt++;
		if (n<=p)break;
		n-=p;
		p*=2;
	}
	cout<<cnt<<endl;
	return 0;
}