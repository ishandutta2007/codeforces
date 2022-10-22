#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...); 1;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+2;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		string s;
		cin>>s;
		n=stoi(s);
		if (n%7==0) {cout<<n<<'\n';continue;}
		for (int i=0;i<10;i++)
		{
			s.back()=i+'0';
			if (stoi(s)%7==0) {cout<<s<<'\n';break;}
		}
	}
}