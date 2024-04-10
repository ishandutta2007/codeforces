#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int mod = (int)1e9 + 7, inv2 = (mod + 1) / 2, inv3 = (mod + 1) / 3, inv5 = (mod * 2 + 1) / 5, inv7 = (mod + 1) / 7;
const int inv6 = (ll)inv2 * inv3 % mod, inv30 = (ll)inv5 * inv6 % mod, inv42 = (ll)inv6 * inv7 % mod;
const int w[4][8] = {
{0, 1}, 
{0, inv6, inv2, inv3}, 
{0, mod - inv30, 0, inv3, inv2, inv5}, 
{0, inv42, 0, mod - inv6, 0, inv2, inv2, inv7} 
};

int mult(int a, int b){
	return a * (ll)b % mod;
}

int add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int sum(int a, int b){
	int ans = a + b;
	if (ans >= mod) ans -= mod;
	return ans;
}

int bp(int a, int k){
	if (k == 0) return 1;
	if (k % 2 == 1){
		return mult(a, bp(a, k - 1));
	} else {
		int q = bp(a, k / 2);
		return mult(q, q);
	}
}

int inv(int x){
	return bp(x, mod - 2);
}

ll n;

int c[4];

int mysqrt(ll val){
	//cout << "====" << val << endl;
	ll vl = 0, vr = 1e7;
	while(vl + 1 < vr){
		ll vm = (vl + vr) >> 1;
		if (vm * vm <= val)
			vl = vm;
		else
			vr = vm;
	}
	if (vr * vr <= val) assert(0);
	return vl;
}

int main(){
   //	freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int nn = n % mod;

    c[0] = mult(nn, mult(nn + 1, nn + 2));
    c[1] = sum(mult(3, nn), 4);
    c[2] = (mod - sum(mult(3, nn), 6)) % mod;
    c[3] = 2;

    int ans = 0;
    for (int x = 1; x * (ll)x <= n; x++){
    	int ymax = mysqrt(n - x * (ll)x);

    	int x2 = mult(x, x);
    	int x4 = mult(x2, x2);
    	int x6 = mult(x2, x4);

    	//int sumy2 = mult(mult(ymax, mult(ymax + 1, ymax * 2 + 1)), inv(6));
    	//int sumy4 = mult(ymax, mult(ymax + 1, mult(2 * ymax + 1, mult( sum(mod - 1, sum(mult(3, mult(ymax, ymax)), mult(3, ymax))) , inv(30)))));
    	//int sumy6 = mult(ymax, mult(ymax + 1, mult(2 * ymax + 1, mult( sum(sum(mult(3, bp(ymax, 4)), mult(6, bp(ymax, 3))), sum(1, mod - 3 * ymax)), inv(42)))));

    	int sumy2 = 0, sumy4 = 0, sumy6 = 0;

    	int tmp = ymax;
    	for (int i = 1; i <= 3; i++){
    		add(sumy2, mult(w[1][i], tmp));
    		add(sumy4, mult(w[2][i], tmp));
    		add(sumy6, mult(w[3][i], tmp));
    		tmp = mult(tmp, ymax);
    	}
    	for (int i = 4; i <= 5; i++){
    		add(sumy4, mult(w[2][i], tmp));
    		add(sumy6, mult(w[3][i], tmp));
    		tmp = mult(tmp, ymax);
    	}
    	for (int i = 6; i <= 7; i++){
    		add(sumy6, mult(w[3][i], tmp));
    		tmp = mult(tmp, ymax);
    	}

    	//0
    	add(ans, mult(ymax + 1, c[0]));
    	//1
    	add(ans, mult(ymax + 1, mult(x2, c[1])));
    	add(ans, mult(sumy2, c[1]));
    	//2
    	add(ans, mult(ymax + 1, mult(x4, c[2])));
    	add(ans, mult(c[2], mult(mult(2, x2), sumy2)));
    	add(ans, mult(c[2], sumy4));
    	//3
    	add(ans, mult(ymax + 1, mult(x6, c[3])));
    	add(ans, mult(mult(3, c[3]), mult(x4, sumy2)));
    	add(ans, mult(mult(3, c[3]), mult(x2, sumy4)));
    	add(ans, mult(c[3], sumy6));
    }
	ans = mult(ans, 4);
	add(ans, c[0]);
	ans = mult(ans, inv(6));
	cout << ans;
}