#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int father[maxn];
int dep[maxn];
int cnt[maxn];
int n;
int main(){
	scanf("%d",&n);
	dep[1]=1;
	for (int i=2;i<=n;i++){
		scanf("%d",&father[i]);
		dep[i] = dep[father[i]]+1;
		cnt[dep[i]]++;
	}
	int ans =1;
	for (int i=2;i<=n;i++){
		ans += cnt[i]%2;
	}
	cout<<ans<<endl;
	return 0;
}