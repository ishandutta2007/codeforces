
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1100000;
int a[N],n;
int b[N];
long long get(int i,int x) 
{
	return lower_bound(b+1,b+i,x)-b;
}
int main()
{
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int base=1;base<=20000000;base<<=1)
	{
		long long now=0;
		for(int i=1;i<=n;i++)b[i]=a[i]&(base*2-1);
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)
            now=(now+(get(i,2*base-b[i])-get(i,base-b[i]))+(i-get(i,3*base-b[i])))%2;
        ans+=now*base;
	}
	cout<<ans<<endl;
	return 0;
}