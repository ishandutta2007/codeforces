#include <bits/stdc++.h>
using namespace std;
#define MAX 300000
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
int n , a[MAX] , use[MAX] , pre[MAX] , ans[MAX];
vector<int> v[MAX];
void DFS(int now , int fa , int deep){
	if(now == 1) pre[now] = a[now];
	else pre[now] = __gcd(pre[fa] , a[now]);
	
	int tmp = (now == 1) ? pre[now] : pre[fa];
	
	for(int i = 1 ; i <= a[now] ; i ++){
		if(i * i > a[now]) break;
		else if(i * i == a[now]){
			use[i] ++;
			if(use[i] >= deep - 1) tmp = max(tmp , i);
		}
		else if(a[now] % i == 0){
			use[i] ++;
			if(use[i] >= deep - 1) tmp = max(tmp , i);
			use[a[now] / i] ++;
			if(use[a[now] / i] >= deep - 1) tmp = max(tmp , a[now] / i);
		}
	}
	ans[now] = tmp;
	
	for(int i = 0 ; i < v[now].size() ; i ++){
		int to = v[now][i];
		if(to == fa) continue;
		DFS(to , now , deep + 1);
	}
	
	for(int i = 1 ; i <= a[now] ; i ++){
		if(i * i > a[now]) break;
		else if(i * i == a[now]) use[i] --;
		else if(a[now] % i == 0){
			use[i] -- , use[a[now] / i] --;
		}
	}
}
int main()
{
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n){
		int q , w;
		cin >> q >> w;
		v[q].pb(w);
		v[w].pb(q);
	}
	DFS(1 , 0 , 1);
	REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
  	return 0;
}