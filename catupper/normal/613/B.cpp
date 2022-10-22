#include<iostream>
#include<algorithm>
#include<set>
#include<string>
#include<cmath>
#include<cstdio>

using namespace std;
#define INF (1LL << 60)

typedef long long Int;
typedef pair<Int, Int> P;

Int n, A, cf, cm, m;
P a[108000];
P b[108000];
Int res;
Int ans;
Int answer[108000];


Int solve(Int nn, Int x){
	if(nn == 0)return A;
	Int cnt = upper_bound(b, b + nn, P(x, INF)) - b;cnt--;
	x -= b[cnt].first;
	return min(a[cnt].first + x / (cnt+1), A);
}

int main(){
	cin >> n >> A >> cf >> cm >> m ;
	for(Int i = 0;i < n;i++)cin >> a[i].first, a[i].second = i;
	sort(a, a + n);
	Int sum = 0;
	for(Int i = 0;i < n;i++)b[i] = a[i];
	for(Int i = 0;i < n;i++){
		b[i].first = a[i].first * i - sum;
		sum += a[i].first;
	}
	Int need = 0;
	for(Int i = 0;i <= n;need += A - a[max(n - i - 1, 0LL)].first, i++){
		if(need > m)break;
		Int minval = solve(n - i, m - need);
		Int tmp = i * cf + cm * minval;
		if(res < tmp){
			res = tmp;
			ans = i;
		}
	}
	
	need = 0;
	for(Int i = 0;i < ans;need += A - a[n - i - 1].first, i++)answer[a[n - i - 1].second] = A;
	Int minval = solve(n - ans, m - need);
	for(Int i = ans;i < n;i++)answer[a[n - i - 1].second] = max(a[n - i - 1].first, minval);
	cout << res << endl;
	for(Int i = 0;i < n;i++)cout << answer[i] << " " ;cout << endl;
	
	return 0;
}