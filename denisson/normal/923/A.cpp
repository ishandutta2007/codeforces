#include <bits/stdc++.h>
                      
using namespace std;
              
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[1000007];
int ans = 1e9;

int dd[33];
int kk = 0;

void check(int x){
	if (a[x] == 0) return;
	kk = 0;
	int save = x;
	while(1){
		if (a[x] == 0) break;
		dd[kk++] = a[x];
		x /= a[x];
	}
	dd[kk++] = x;
	for (int i = 0; i < kk; i++){
		if (save - dd[i] + 1 >= 3) ans = min(ans, save - dd[i] + 1);
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 2; i < 1000007; i++) if (a[i] == 0){
    	for (int j = 2 * i; j < 1000007; j += i){
    		if (a[j] == 0) a[j] = i;
    	}
    }
    int save = n;
    set<int> se;
    while(1){
    	if (a[n] == 0) break;
    	se.insert(a[n]);
    	n /= a[n];
    }
    se.insert(n);
    ans = save;
    for (int x : se){
    	for (int i = save; i >= save - x + 1; i--){
    		check(i);
    	}
    }
    cout << ans;
}