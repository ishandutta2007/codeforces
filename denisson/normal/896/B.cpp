#include <bits/stdc++.h>
                   
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m, c;
int a[1111];
int x;

void ask(int pos){
	cout << pos + 1 << endl;
	a[pos] = x;
	bool st = 1;
	for (int i = 0; i < n; i++) if (a[i] == 0) st = 0;
	if (st) exit(0);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> c;
    while(1){
    	cin >> x;
    	if (x <= c / 2){
    		for (int i = 0; i < n; i++) if (a[i] == 0 || a[i] > x){
    			ask(i);
    			break;
    		}
    	} else {
    		for (int i = n - 1; i >= 0; i--) if (a[i] == 0 || a[i] < x){
    			ask(i);
    			break;
    		}
       	}

    }
}