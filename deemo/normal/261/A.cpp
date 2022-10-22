#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int>	vec, sec;

int main(){
	scanf("%d", &m);
	sec.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &sec[i]);
	sort(sec.begin(), sec.end());
	int mini = sec[0];

	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	sort(vec.begin(), vec.end());

	long long sum = 0;
	for (int i = n - 1; i >= 0; i -= (mini + 2)){
		int j = i;
		while (j > i - mini && j >= 0){
			sum += vec[j];
			j--;
		}
	}
	printf("%I64d\n", sum);
	return 0;
}