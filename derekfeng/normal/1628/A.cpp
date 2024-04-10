#include<bits/stdc++.h>
using namespace std;
int T,n,cur;
queue<int>pos[200004];
void sol(){
	cur=0,scanf("%d",&n);
	for(int i=0;i<=n;i++)while(!pos[i].empty())pos[i].pop();
	for(int i=1,x;i<=n;i++)scanf("%d",&x),pos[x].push(i);
	vector<int>ans;
	for(;cur<n;){
		int g=0,ncur=cur;
		for(;;){
			while(!pos[g].empty()&&pos[g].front()<=cur)pos[g].pop();
			if(pos[g].empty())break;
			ncur=max(ncur,pos[g].front()),g++;
		}
		if(g==0)ncur++;
		ans.push_back(g);
		cur=ncur,g++;
	}
	printf("%d\n",ans.size());
	for(auto x:ans)printf("%d ",x);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}