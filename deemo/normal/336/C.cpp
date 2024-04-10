#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 1e5 + 20;
const int LOG = 31;

int n;
int a[max_n];
vector<int>	vec[LOG + 2];
int save[LOG + 2];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		for (int j = 0; j < LOG; j++)
			if ((a[i] >> j) & 1){
				vec[j].push_back(a[i]);
				if (vec[j].size() == 1)	
					save[j] = a[i];
				else
					save[j] = a[i] & save[j];
			}
	}

	int ans = 0, cnt = 0;
	for (int i = 0; i < LOG; i++)
		for (int j = i; j < LOG; j++){
			int t = save[j];
			if (t == 0)	continue;
			if (save[j] & ((1 << j) - 1))	continue;
			if (ans < i + 1 || (ans == i + 1 && vec[j].size() > cnt)){
				ans = i + 1;
				cnt = vec[j].size();
			}
		}
	printf("%d\n", (int)vec[ans - 1].size());
	for (int i = 0; i < vec[ans - 1].size(); i++)
		printf("%d ", vec[ans - 1][i]);
	printf("\n");
	return 0;
}