using namespace std;
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
#define all(x) (x).begin(),(x).end()
#define fpi(x) freopen(x,"r",stdin);
#define fpo(x) freopen(x,"w",stdout);
#define fprio fpi("in.txt");fpo("out.txt"):
#define fast ios::sync_with_stdio(false);
/*************************************************/
int no[5],x,ma[5];
int main()
{
	cin>>x;
	if (x) no[1]=no[4]=1;
	cin>>x;
	if (x) no[1]=no[3]=1;
	cin>>x;
	if (x) no[1]=no[2]=1;
	cin>>ma[1];
	cin>>x;
	if (x) no[2]=no[1]=1;
	cin>>x;
	if (x) no[2]=no[4]=1;
	cin>>x;
	if (x) no[3]=no[2]=1;
	cin>>ma[2];
	cin>>x;
	if (x) no[3]=no[2]=1;
	cin>>x;
	if (x) no[1]=no[3]=1;
	cin>>x;
	if (x) no[3]=no[4]=1;
	cin>>ma[3];
	cin>>x;
	if (x) no[3]=no[4]=1;
	cin>>x;
	if (x) no[2]=no[4]=1;
	cin>>x;
	if (x) no[4]=no[1]=1;
	cin>>ma[4];
	cout<<(((no[1]&&ma[1])||(no[2]&&ma[2])||(no[3]&&ma[3])||(no[4]&&ma[4]))?"YES":"NO");
	return 0;
}