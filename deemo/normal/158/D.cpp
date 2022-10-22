#include<cstdio>
#include<vector>

using namespace std;

const int max_n = 3e4+50;

vector<int>	vec;
int n, ans = -1e9;

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0 ; i < n; i++)	
		scanf("%d", &vec[i]);
	for (int i = 1; i <= n && n / i >= 3; i++){
		if (n % i != 0)	continue;
		for (int j = 0; j < i; j++){
			int c = (j + i) % n, sum = vec[j];
			while (c != j){
				sum += vec[c];
				c = (c + i) % n;
			}
			ans = max(ans, sum);
		}	
	}
	printf("%d\n", ans);
	return	0;
}