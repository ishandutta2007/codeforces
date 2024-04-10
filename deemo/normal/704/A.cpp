#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 3e5 + 10;

int n, q;
set<int>	st, tt[MAXN];

int main(){
	scanf("%d %d", &n, &q);
	int k = 1;
	for (int i = 1; i <= q; i++){
		int type;	scanf("%d", &type);
		if (type == 1){
			int x;	scanf("%d", &x);
			st.insert(k);
			tt[x].insert(k);
			k++;
		}
		else if (type == 2){
			int x;	scanf("%d", &x);
			while (tt[x].size()){
				st.erase(*tt[x].begin());
				tt[x].erase(tt[x].begin());
			}
		}
		else{
			int x;	scanf("%d", &x);
			while (st.size() && *st.begin() <= x)
				st.erase(st.begin());
		}
		printf("%d\n", (int)st.size());
	}
	return 0;
}