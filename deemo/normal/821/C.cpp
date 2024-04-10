#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, sec[MAXN], sz;
set<int> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int cur = 1, ans = 0;
	for (int i = 0; i < n+n; i++){
		string s; cin >> s;
		if (s[0] == 'a'){
			int x; cin >> x;
			sec[sz++] = x;
		}
		else{
			int tp = -1;
			if (sz)
				tp = sec[sz-1];
			else
				tp = *st.begin();
			
			if (tp == cur){
				if (sz)
					sz--;
				else{
					st.erase(st.begin());
				}
			}
			else{
				while (sz){
					sz--;
					st.insert(sec[sz]);
				}
				st.erase(st.begin());
				ans++;
			}
			cur++;
		}
	}
	cout << ans << endl;
	return 0;
}