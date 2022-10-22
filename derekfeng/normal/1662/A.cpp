#include<bits/stdc++.h>
using namespace std;
int t,n;
vector<int>v[11];
int main(){
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<=10;i++)v[i].clear();
		scanf("%d",&n);
		while(n--){
			int b,d;scanf("%d%d",&b,&d);
			v[d].push_back(b);
		}
		int ans=0;
		for(int i=1;i<=10;i++){
			if(v[i].empty())ans=-1e9;
			else{
				sort(v[i].begin(),v[i].end());
				ans+=v[i].back();
			}
		}
		if(ans<0)puts("MOREPROBLEMS");
		else printf("%d\n",ans);
	}
}