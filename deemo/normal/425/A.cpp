#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int MAXN = 200 + 4;
const int INF = 1e9 + 2;

int n, k, vec[MAXN], ans = -INF;
multiset<int>	st, ss;

int main(){
	cin >> n >> k;	
	for (int i = 0; i < n; i++)	cin >> vec[i];
	for (int i = 0; i < n; i++){
		st.clear();
		for (int j = 0; j < n; j++)	st.insert(vec[j]);
		ss.clear();
			
		int sum = 0;
		for (int j = i; j < n; j++){
			st.erase(st.find(vec[j]));
			ss.insert(vec[j]);
			sum += vec[j];

			int z = 0;
			auto it = st.end(), it2 = ss.begin();	
			if (st.size()){
				it--;
				for (int w = 0; w < k; w++){
					if (*it < *it2)	break;
					z += *it;
					z -= *it2;

					if (it == st.begin())	break;
					it--;	it2++;
					if (it2 == ss.end())	break;
				}
			}
			ans = max(ans, sum + z);
		}
	}
	cout << ans << "\n";
	return	0;
}