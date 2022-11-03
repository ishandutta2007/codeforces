#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, w1, w2;

int ans[1000007];

void solve(int c1, int c2){
	for (int i = 0; i < n; ){
		if (c1 > 0){
			for (int j = 0; j < w1 - 1; j++) ans[i + j] = i + j + 1;
			ans[i + w1 - 1] = i;
			c1--;
			i += w1;
		} else {
			for (int j = 0; j < w2 - 1; j++) ans[i + j] = i + j + 1;
			ans[i + w2 - 1] = i;
			c2--;
			i += w2;
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w1 >> w2;
    for (int i = 0; ; i++){
    	int val = i * w1;
    	if (val > n) cout << -1, exit(0);
    	if ((n - val) % w2 == 0){
    		solve(i, (n - val) / w2);
    		exit(0);
    	}
    }
}