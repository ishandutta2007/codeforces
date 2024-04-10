#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
using namespace std;
int main()
{
	int n,l;
	scanf("%d%d",&n,&l);
	int ans=2147483647;
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		if (l%x)continue;
		ans=min(ans,l/x);
	}
	cout<<ans<<endl;
}