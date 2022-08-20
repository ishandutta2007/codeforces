#include <bits/stdc++.h>
using namespace std;
 
int cur[5000005], factors[5000005];
 
int main() {
	for (int i = 1; i <= 5000000; ++i) cur[i] = i;
	for (int i = 1; i <= 5000000; ++i) if (cur[i] > 1)
		for (int j = i; j <= 5000000; j += i)
			while (cur[j]%i == 0) {
				cur[j] /= i;
				++factors[j];
			}
	for (int i = 1; i <= 5000000; ++i) factors[i] += factors[i-1];
	int T; scanf("%d",&T);
	string ans;
	for (int i = 0; i < T; ++i) {
		int a,b; scanf("%d%d",&a,&b);
		ans += to_string(factors[a]-factors[b])+"\n";
	}
	printf("%s",ans.c_str());
}