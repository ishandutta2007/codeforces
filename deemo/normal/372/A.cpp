#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int MAXN = 5e5 + 10;

int n, vec[MAXN];
multiset<int>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec, vec + n);
	for (int i = n/2; i < n; i++)
		st.insert(vec[i]);

	int cnt = 0;
	for (int i = 0; i < n/2; i++){
		multiset<int>::iterator it = st.lower_bound(2 * vec[i]);
		if (it == st.end())	break;
		st.erase(it);
		cnt++;
	}
	cout << n - cnt << endl;
	return 0;
}