//I'm scared to death if I let you in that you'll see I'm just a fake..
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int max_n = 1e5 + 20;

int n, m;
int a[max_n], b[max_n];
vector<int>	st, sst, ans;

int main(){
	scanf("%d%d", &n, &m);	
	for (int i = 0; i < n + n; i++){
		int temp;	scanf("%d", &temp);
		if (i < n)	a[temp]++;
		else	b[temp]++;
	}
	for (int i = m - 1; i >= 0; i--){
		while (b[m - 1 - i]--)	st.push_back(m - 1 - i);
		while (a[i]--){
			if (st.size())	
				ans.push_back(i + st.back()), st.pop_back();
			else
				sst.push_back(i);
		}
	}
	int ind = 0;
	while (st.size())
		ans.push_back((st.back() + sst[ind++]) % m),	st.pop_back();
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for (int u:ans)
		printf("%d ", u);
	printf("\n");
	return 0;
}