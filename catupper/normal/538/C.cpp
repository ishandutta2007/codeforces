#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;
#define INF (1LL<<60)
#define MOD 1000000007

Int n, m;
Int h[1080000];
Int d[1080000];

Int solve(Int a, Int b, Int d){
	if(a < b)swap(a,b);
	Int dif = a-b;
	if(dif > d)return INF;
	d -= dif;
	return a + d / 2;
}

int main(){
	cin >> n >> m;
	for(Int i = 0;i < m;i++){
		cin >> d[i] >> h[i];
	}
	Int res = h[0];
	res = max(res, h[0] + d[0] - 1);
	res = max(res, h[m-1] + n - d[m-1]);
	for(Int i = 1;i < m;i++){
		res = max(res, solve(h[i-1], h[i], d[i] - d[i-1]));
	}
	if(res == INF)cout << "IMPOSSIBLE" << endl;
	else cout << res << endl;
	return 0;
}