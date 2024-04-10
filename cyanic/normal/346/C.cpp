#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100009;
vector<int> x1, x2;
int n, a, b, ans, x, N = 0, best;

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &x);
		x1.push_back(x);
	}
	scanf("%d%d", &a, &b);
	sort(x1.begin(), x1.end());
	for (int i=1; i<=x1.size()-1; i++)
		if (x1[i] != x1[N]) x1[++N] = x1[i];
	while (x1.size() > N+1) x1.pop_back();
	while (a > b){
		ans++;
		best = a-1;
		for (int i=0; i<x1.size(); i++)
			if (a - a%x1[i] >= b){
				best = min(best, a - a%x1[i]);
				x2.push_back(x1[i]);
			}
		a = best;
		while (x1.size()) x1.pop_back();
		while (x2.size()){
			x1.push_back(x2.back());
			x2.pop_back();
		}
	}
	printf("%d\n", ans); 
	return 0;
}