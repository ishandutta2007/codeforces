#include<bits/stdc++.h>
using namespace std;
vector<int> nei[1000001];
bitset<1000001> vis;
int main(){
//	cout<<vis;
	int n,m,lim,c=0,sum=0;scanf("%d%d%d",&n,&m,&lim);
	while(m--){
		int x,y;scanf("%d%d",&x,&y);
		nei[x].push_back(y);nei[y].push_back(x);
	}
//	for(int i=1;i<=n;i++){for(int j=0;j<nei[i].size();j++)cout<<nei[i][j]<<" ";puts("");}
	for(int i=1;i<=n;i++)if(!vis[i]){
		int no=0;
		c++;
		queue<int> q;q.push(i);vis.set(i);
		while(q.size()){
			int x=q.front();q.pop();
//			cout<<x<<":";
			no++;
			for(int j=0;j<nei[x].size();j++){
				int to=nei[x][j];
//				cout<<to<<" ";
				if(!vis[to])vis.set(to),q.push(to);
			}
//			puts("");
		}
		sum+=min(no,lim);
//		cout<<c<<" "<<no<<"\n";
	}
	printf("%d",max(lim==1?c-2:c-1-(sum>>1),0));
	return 0;
}
/*1
3 3 2
1 2
2 3
3 1
*/
/*2
4 2 2
1 2
3 4
*/
/*3
4 0 2
*/