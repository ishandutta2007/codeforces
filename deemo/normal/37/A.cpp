#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

set<int>	st;
int cnt[20000];

int main(){
	int n;	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		cnt[x]++;
		mx = max(mx, cnt[x]);
		st.insert(x);
	}
	cout << mx << " " << st.size() << "\n";
	return	0;
}