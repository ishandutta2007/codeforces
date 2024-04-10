#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
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
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
int n,m,q,i,j,l,r,use[200005],pre[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for (i=1;i<=n;i++)
	{
		cin>>l>>r;
		use[l-1]--;
		use[r]++;
	} 
	for (i=200000;i>0;i--)
	{
		use[i]+=use[i+1];
	}
	for (i=1;i<=200000;i++)
	{
		pre[i]=pre[i-1]+(use[i]>=m);
	}
	for (i=1;i<=q;i++)
	{
		cin>>l>>r;
		cout<<pre[r]-pre[l-1]<<endl;
	}
	return 0;
}