#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int to[maxn];
vector<int> cnt;
bool vis[maxn];
int n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",to+i);
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			int now =i;
			int temp =0;
			while (!vis[now]){
				temp++;
				vis[now] = true;
				now = to[now];
			}
			cnt.push_back(temp);
		}
	}
	sort(cnt.begin(),cnt.end(),cmp);
	long long ans =0;
	if (cnt.size()==1){
		ans = 1LL*n*(n);
	}else{
		int x = cnt[0]+cnt[1];
		ans = 1LL*x*(x);
		int too = cnt.size();
		for (int i=2;i<too;i++){
			int y = cnt[i];
			ans += 1LL*y*(y);
		}
	}
	cout<<ans<<endl;
	return 0;
}