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
int n,m,i,j,l,r,k,l1,l2,t1,t2;
string st;
bool x1,x2;
char ans[1000005];
string sb,ta,sa,tb;
int main()
{
	fast;
	cin>>sa;
	sort(sa.begin(),sa.end());
	cin>>sb;
	sort(sb.begin(),sb.end());
	reverse(sb.begin(),sb.end());
	//cerr<<sa<<sb;
	n=sa.length();
	l=1;r=n;
	memset(ans,'_',sizeof(ans));
	for (j=1;j<=n;j+=2)
	{
		 if (sa[l1]<sb[l2]&&!x1)
		 {
		 	ans[l++]=sa[l1++];
		}
		 else 
		 {
		 	if (!x1)
			{
			 	x1=1;
			 	for (k=j;k<=n;k+=2)
			 	{
			 		ta.push_back(sa[l1++]);
			 	}
			 	sort(ta.begin(),ta.end());
			 	reverse(ta.begin(),ta.end());
			}
		 	ans[r--]=ta[t1++];
		 }
	//	for (i=1;i<=n;i++) cerr<<ans[i];
	//	cerr<<endl;
		 if (j+1>=n&&n%2) break;
		 if (sa[l1]<sb[l2]&&!x2)
		 {
		 	ans[l++]=sb[l2++];
		 }
		 else 
		 {
		 	if (!x2)
			{
			 	x2=1;//cerr<<x2<<endl;
			 	for (k=j+1;k<=n;k+=2)
			 	{
			 		tb.push_back(sb[l2++]);
			 	}
			 	sort(tb.begin(),tb.end());
			}
		 	ans[r--]=tb[t2++];
		 }
		//for (i=1;i<=n;i++) cerr<<ans[i];
		//cerr<<endl;
	}
	for (i=1;i<=n;i++) cout<<ans[i];
	return 0;
}