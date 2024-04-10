#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int main(){
	int n,k; scanf("%d%d",&n,&k);
	mp.clear();
	for(int i=1;i<=k+1;++i){
		printf("?");
		for(int j=1;j<=k+1;++j)
			if(i!=j)
				printf(" %d",j);
		puts("");
		fflush(stdout);
		pair<int,int> t; scanf("%d%d",&t.second,&t.first);
		mp[t]++;
	}
	printf("! %d\n",mp.rbegin()->second);
	return 0;
}