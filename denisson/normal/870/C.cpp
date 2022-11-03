#include <bits/stdc++.h>
          
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int main(){ 
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
    	int n;
    	cin >> n;
    	if (n <= 3){
    		cout << "-1\n";
    		continue;
    	}
    	if (n % 2 == 0){
    		if (n % 4 == 0) cout << n / 4 << "\n";
    		else cout << (n - 6) / 4 + 1 << "\n";
    	} else {
    		if (n < 9){
	    		cout << "-1\n";
	    		continue;
    		}
    		n -= 9;
    		if (n == 0){
    			cout << 1 << "\n";
    			continue;
    		}
    		if (n <= 3){
	    		cout << "-1\n";
	    		continue;
    		}
    		if (n % 4 == 0) cout << n / 4 + 1 << "\n";
    		else cout << (n - 6) / 4 + 1 + 1 << "\n";
    	}
    }
}