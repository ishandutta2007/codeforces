#include<cstdio>
#include<vector>

using namespace std;

int n;
vector<int>	vec, p;

int main(){
	scanf("%d", &n);
	vec.resize(n);
	p.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	p[0] = vec[0];
	for (int i = 1; i < n; i++)
		p[i] = p[i - 1] + vec[i];	
	int cnt = 0;
	for (int i = 0; i < n - 1; i++)
		if (p[i] == p[n - 1] - p[i])	cnt++;
	printf("%d\n", cnt);
	return 0;
}