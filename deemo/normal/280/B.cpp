#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int n;
vector<int>	vec;

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	vector<int>	st;
	int ans = 0;
	for (int i = 0; i < n; i++){
		int t = -1;
		while (st.size() && st.back() < vec[i]){
			t = max(st.back(), t);
			ans = max(ans, t ^ vec[i]);
			st.pop_back();
		}
		if (st.size())	
			ans = max(ans, vec[i] ^ (st.back()));
		st.push_back(vec[i]);
	}
	printf("%d\n", ans);
	return 0;
}