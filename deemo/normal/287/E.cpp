#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6 + 20;

int n, m;
int vec[MAXN], ans[MAXN];
vector<int>	st;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &vec[i]);
	reverse(vec, vec + n);
	int temp;	scanf("%d", &temp);
	while (temp--){
		int tm;	scanf("%d", &tm);
		tm = n - tm + 1;
		vec[tm - 1] *= -1;
	}

	for (int i = 0; i < n; i++){
		if (vec[i] < 0){
			ans[i] = vec[i];
			st.push_back(-vec[i]);
		}
		else if (st.empty() || abs(vec[i]) != abs(st.back())){
			ans[i] = -vec[i];
			st.push_back(abs(vec[i]));
		}
		else{
			ans[i] = abs(vec[i]);
			st.pop_back();
		}
	}
	if (st.size()){
		printf("NO\n");
		return 0;
	}

	printf("YES\n");
	reverse(ans, ans + n);
	for (int i = 0 ;i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}