#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int n;
double ans=0.0;
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)ans+=1.0/i;
	printf("%.11lf\n",ans);	
	return 0;
}