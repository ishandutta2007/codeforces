#include<deque>
#include<stdint.h>
#include<set>
#include<stack>
#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define sqr(x) (x)*(x)
#define ll long long
#define mp make_pair
#define pb push_back
#define in insert
#define mtr(x,y,z) mp(mp(x,y),z)
#define fi first
#define se second
#define fpi(x) freopen(x,"r",stdin);
#define fpo(x) freopen(x,"w",stdout);
#define fast ios::sync_with_stdio(false);
using namespace std;
int n,m,i,j,s,x,a,b,c;
int main()
{
	fast; 
	cin>>a>>b>>c>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		if (x<c&&x>b) s++;
	}
	cout<<s;
	return 0;
}