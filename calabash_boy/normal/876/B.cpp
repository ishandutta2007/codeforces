#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5+100;
vector<int> ans[maxm];
int n,k,m;
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for (int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		int flag = x%m;
		ans[flag].push_back(x);
		if (ans[flag].size()>=k){
			printf("Yes\n");
			for (auto t:ans[flag]){
				printf("%d ",t);
			}
			return 0;
		}
	}
	printf("No\n");
	return 0;
}