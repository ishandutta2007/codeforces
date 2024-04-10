#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
long long x,y,l,r,ma,i,j,last,mx,my,c;
set<long long> unluc;
bool first=1;
int main()
{
	cin>>x>>y>>l>>r;
	mx=1;
	for (;;)
	{
		my=1;
		for (;;)
		{
			unluc.insert(mx+my);
			if (my>r/y) break;
			my*=y;
		}
		if (mx>r/x) break;
		mx*=x;
	}
	last=l-1;
	for (set<long long>::iterator it=unluc.begin();it!=unluc.end();it++)
	{
		//cerr<<*it<<' ';
		if (*it<l) continue;
		if (*it>r) break;
		ma=max(ma,*it-last-1); 
		last=*it;
	}
	cout<<max(r-last,ma);
	return 0;
}