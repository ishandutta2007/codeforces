#include <bits/stdc++.h>
#define maxn 1009
using namespace std;
int n,m,k;
int c[maxn],rt[maxn],cnt[maxn];
int p[maxn];
int findset(int x){
	return x == p[x] ? x : p[x] = findset(p[x]);
}
void unionset(int x,int y){
	p[findset(x)] = findset(y);
}
vector<int>a;
int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++)
		cin >> c[i];
	for(int i = 1; i <= n; i++)
		p[i] = i;
	for(int i = 1; i <= m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		unionset(x, y);
	}
	for(int i = 1; i <= n; i++){
		cnt[findset(i)]++;
	}
	for(int i = 1; i <= k; i++){
		a.push_back(cnt[findset(c[i])]);
	}
	sort(a.begin(),a.end());
	long long ans=0;
	int num = 0;
	for(int i = 0; i < k - 1; i++){
		ans += 1LL * a[i] * (a[i] - 1) / 2;
		num += a[i];
	}
	num = n - num;
	ans += 1LL * num * (num - 1) / 2;
	cout << ans - m << endl;
	//system("pause");
	return 0;
}