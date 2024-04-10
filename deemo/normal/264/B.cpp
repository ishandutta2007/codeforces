#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int max_n = 1e5 + 10;

int n, ans;
int d[max_n], c[max_n];
vector<int>	vec, sec;

void get(int x){
	sec.clear();
	for (int i = 1; i * i <= x; i++)
		if (x % i == 0){
			sec.push_back(i);
			if (i != x/i)	sec.push_back(x/i);
		}
}

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	int i = 0;
	for (int x:vec){
		get(x);
		c[i] = 1;
		for (int v:sec)
			if (v != 1)	c[i] = max(c[i], d[v] + 1);

		for (int v:sec)
			d[v] = max(d[v], c[i]);
		ans = max(ans, c[i]);
		i++;
	}
	printf("%d\n", ans);
	return 0;
}