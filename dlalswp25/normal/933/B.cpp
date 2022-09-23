#include <stdio.h>
#include <vector>

using namespace std;

vector<int> V;

int main() {
	long long p;
	int k;
	scanf("%lld %d", &p, &k);
	for(int i = 0; ; i++) {
		if(p == 0) break;
		for(int j = 0; j < k; j++) {
			int add = ((i & 1) ? j : (-j));
			if((p + add) % k == 0) {
				V.push_back(j);
				p = (p + add) / k;
				break;
			}
		}
	}
	printf("%d\n", V.size());
	for(int i = 0; i < V.size(); i++) {
		printf("%d ", V[i]);
	}
	return 0;
}