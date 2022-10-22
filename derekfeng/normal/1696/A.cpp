#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,z,ans=0;scanf("%d%d",&n,&z);
		while(n--){
			int x;scanf("%d",&x);ans=max(ans,x|z);
		}
		printf("%d\n",ans);
	}
}