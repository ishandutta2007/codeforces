#include <bits/stdc++.h>
          
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

const int INF = (int)1e9 + 7;

int n, k;
int a[100007];

int main(){ 
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k == 1){
    	int ans = a[0];
    	for (int i = 0; i < n; i++) ans = min(ans, a[i]);
    	cout << ans;
    } else if (k == 2){
    	int mi = a[0];
    	int ans = -INF;
    	multiset<int> se;
    	for (int i = 0; i < n; i++) se.insert(a[i]);
    	for (int i = 0; i < n - 1; i++){
    		se.erase(se.find(a[i]));
    		mi = min(mi, a[i]);
    		ans = max(ans, max(mi, *se.begin()));
    	}
    	cout << ans;
    } else {
    	int ans = a[0];
    	for (int i = 0; i < n; i++) ans = max(ans, a[i]);
    	cout << ans;
    }
}