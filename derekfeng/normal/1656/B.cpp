#include<bits/stdc++.h>
using namespace std;
int n,k;
map<int,int>mp;
void sol(){
	scanf("%d%d",&n,&k),mp.clear();
	while(n--){
		int x;scanf("%d",&x);
		mp[x]=1;
	}
	for(auto it:mp)
		if(mp.count(it.first+k)){
			puts("YES");
			return;
		}
	puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}