#include <bits/stdc++.h>
#define MAXN 1000100
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;

ll T, n, m, a, b, s[MAXN];

bool check(int x){
	int d = abs(a - b);
	int e = a - 1;
	if(b < a) e = n - a;
	d -= x;
	//cout << d << " " << e << endl;
	if(d <= 0) return false;
	for(int i = 0; i < x; i++){
		if(i + s[x - i - 1] >= e + d + x)
			return false;
	}
	return true;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
    	cin >> n >> m >> a >> b;
    	for(int i = 0; i < m; i++){
    		cin >> s[i];
    	}
    	sort(s, s + m);
    	//cout << check(2) << endl;
    	int l = 0, r = m;
    	while(l < r){
    		int mid = (l + r) / 2;
    		if(check(mid)) l = mid + 1;
    		else r = mid;
    	}
    	if(!check(l)) l--;
    	cout << l << endl;
    }
}