#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
const db eps = 1e-7;

vector<db> func(vector<db> a, vector<db> b){
	while(1){
		int sd = (int)a.size() - b.size();	
		db k = a.back() / b.back();
		for (int i = (int)a.size() - 1; i >= 0; i--) if (i - sd >= 0){
			a[i] -= b[i - sd] * k;
		}
		while(a.size() && abs(a.back()) < eps) a.pop_back();
		if (a.size() < b.size()) return a;
	}
}

int calc(vector<db> a, vector<db> b){
	/*for (db x : a) cout << x << ' ';
	cout << endl;
for (db x : b) cout << x << ' ';
	cout << endl;
//cout << endl;*/
	if (b.size() == 0) return 0;
	return calc(b, func(a, b)) + 1;
}

int getval(){
	if (rand() % 2 == 0) return 1;
	return -1;
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(1){
    	vector<db> a, b;
    	for (int i = 0; i < n; i++) a.pub(getval());
    	for (int i = 0; i < n - 1; i++) b.pub(getval());
    	a.pub(1);
    	b.pub(1);
    	//cout << a.size() << ' ' << b.size() << endl;
    	//exit(0);
    	//cout << calc(a, b) << endl;
    	if (calc(a, b) == n){
    		cout << (int)a.size()  - 1<< endl;
    		for (int x : a) cout << x << ' ';
    		cout << endl;
    		cout << (int)b.size() - 1 << endl;
    		for (int x : b) cout << x << ' ';
    			exit(0);
    	}
    }
}