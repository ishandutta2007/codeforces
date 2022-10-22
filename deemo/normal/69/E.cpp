#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 30;

int n, k;
int vec[MAXN];
set<int>	st;
map<int, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	
	for (int i = 0; i < k - 1; i++){
		mp[vec[i]]++;
		if (mp[vec[i]] != 1)
			st.erase(vec[i]);
		else
			st.insert(vec[i]);
	}

	for (int i = k - 1; i < n; i++){
		if (i >= k){
			mp[vec[i - k]]--;
			if (mp[vec[i - k]] != 1)
				st.erase(vec[i - k]);
			else
				st.insert(vec[i - k]);
		}
		mp[vec[i]]++;
		if (mp[vec[i]] == 1)
			st.insert(vec[i]);
		else
			st.erase(vec[i]);
		set<int>::iterator it = st.end();
		if (it == st.begin())
			cout << "Nothing\n";
		else{
			it--;
			cout << *it << "\n";
		}
	}
	return 0;
}