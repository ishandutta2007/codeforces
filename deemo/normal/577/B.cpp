#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int max_m = 1e3 + 50;

int n, m;
vector<int>	vec;
bool d[max_m], z[max_m];

int main(){
	scanf("%d%d", &n, &m);
	if (n >= m){
		printf("YES\n");
		return	0;
	}
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]), vec[i] %= m;
	
	d[0] = 1;
	for (int i = 0; i < n; i++){
		int t = vec[i];
		int temp = (m - t) % m;
		if (d[temp]){
			printf("YES\n");
			return 0;
		}
		copy(d, d + m, z);
		for (int j = 0; j < m; j++)
			if (d[j])	z[(j + t) % m] = 1;
		copy(z, z + m, d);
	}
	printf("NO\n");
}