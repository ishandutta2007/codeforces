#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int>vis;
void sol(){
	scanf("%d",&n),vis.clear();
	while(n--){
		int x;scanf("%d",&x);
		vis[x]=1;
	}
	if(vis[1]&&(vis[2]||vis[0]))puts("NO");
	else if(vis[1]){
		for(auto it:vis)if(it.first>2&&it.second>0){
			if(vis[it.first+1]>0){
				puts("NO");
				return;
			}
		}
		puts("YES");
	}else puts("YES");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}