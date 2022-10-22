#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<iostream>

using namespace std;
typedef long long ll;
int n,ans;
int main(){
//	ios::sync_with_stdio(false);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k = i ^ j;
			if(j <= k && k <= n && i + j > k) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}