#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
int t,n,m,a,b,c,book[100005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),book[b]=1;
		int root=0;
		for (int i=1;i<=n;i++)
			if (book[i]==0)root=i;
		for (int i=1;i<=n;i++)
			if (i!=root)printf("%d %d\n",root,i);
		for (int i=1;i<=n;i++)book[i]=0;
	}
	return 0;
}