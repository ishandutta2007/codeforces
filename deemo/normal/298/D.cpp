#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

const int MAX = 1e5 + 20;

int n, m, k;
int a[MAX];
multiset<int>	st;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < m; i++){
		int temp;	scanf("%d", &temp);
		st.insert(temp);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++){
		int x = a[i];
		multiset<int>::iterator it = st.lower_bound(x);
		if (it != st.end()){
			cnt++;
			st.erase(it);
		}
	}
	if (cnt < n)	printf("YES\n");
	else	printf("NO\n");
	return 0;
}