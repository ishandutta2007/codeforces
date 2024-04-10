/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,f[200100],deg[200100];
vector<int>v[200100];
priority_queue<pair<int,int> >q;
bool vis[200100];
int main(){
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof(f));
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[y].push_back(x),deg[x]++;
	q.emplace(-(f[n]=0),n);
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;vis[x]=true;
		for(auto y:v[x]){
			if(f[y]>f[x]+deg[y])q.emplace(-(f[y]=f[x]+deg[y]),y);
			deg[y]--;
		}
	}
	printf("%d\n",f[1]);
	return 0;
}