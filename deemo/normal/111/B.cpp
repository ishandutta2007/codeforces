#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int max_n = 1e5 + 10;

#define pb(x) push_back(x)

int n;
vector<int>	vec, gec;
vector<int>	sec(max_n, -1);

void get(int x){
	gec.clear();
	for (int i = 1; i * i <= x; i++){
		if (x % i != 0)	continue;
		gec.pb(i);
		if (x / i != i)
			gec.pb(x/i);
	}
}

int main(){
	scanf("%d", &n);
	int j = 0;
	while(n--){
		int t, x;	scanf("%d%d", &x, &t);
		get(x);
	
		int ans = 0;
		for (int i = 0; i < gec.size(); i++){
			int y = gec[i];
			bool fl = 0;
			if (sec[y] == -1)	fl = 1;
			if (sec[y] + t < j)	fl = 1;
			if (fl)	ans++;
		}	
		printf("%d\n", ans);

		for (int i = 0; i < gec.size(); i++)
			sec[gec[i]] = j;
		j++;
	}
	return 0;
}