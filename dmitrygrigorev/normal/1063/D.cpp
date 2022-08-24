#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans = -1e18, INF = 2e18;
int n, p, t, k;
int ex(int a, int b){
    if (INF/a <= b) return INF;
    return a*b;
}
int prev(int L, int C){
    int l = 0, r = 1e18;
    while (r - l > 1){
        int m = (l+r)/2;
        int cnd = ex(C, m);
        if (cnd > L) r = m;
        else l = m;
    }
    return l;
}
int check(int L, int R, int C){
    L--;
    if (L < 0 && R < 0) return false;
    if (L < 0 && R >= 0) return true;
    int prevL = prev(L,C), prevR = prev(R, C);
    if (prevL==prevR) return false;
    return true;
}
void sort_a(int da){
    for (int sum=0; sum <= n; sum++){
        int L = da, R = min(sum, p);
        L = max(L, sum-t);
        if (L > R) continue;
        int C = n+sum;
        int kl = k-R, kr = k-L;
      //  cout << sum << " " << kl << " " << kr << " " << C << endl;
        bool have = check(kl, kr, C);
        if (have) ans = max(ans, sum);
    }
}
int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}
int Get(int x, int d, int v){
    int df = v-x;
    if (df > 0) return (df+abs(d)-1) / d;
    return df/d;
}
pair<int, int> get(int x, int delta, int a, int b){
    if (delta < 0){
        delta*=-1, x*=-1, a*=-1, b*=-1;
        swap(a, b);
    }
    int gg = Get(x, delta, a);
    //cout << gg << " " << x << " " << delta << " " << a << endl;
    int kk = Get(x, delta, b+1);
    //cout << kk << " " << x << " " << delta << " " << b+1 << endl;
    kk--;
    return {gg, kk};
}
void sort_x(int da){
    if (k <= p){
        ans = max(ans, k+t);
    }
    for (int i=1; i <= 1e7; i++){
        int K = k - i*n;
        if (K < 0) break;
        int A = i+1, B = i, C = K;
        //if (i==1) cout << A << " " << B << " " << C << endl;
        int x0, y0, g;
        bool tk = find_any_solution(A, B, C, x0, y0, g);
        if (tk == false) continue;
        pair<int, int> e = get(x0, -i, da, p);
        pair<int, int> f = get(y0, i+1, 0, t);
        //if (x0-i*e.first > p) cout << x0 << "??" << e.first << " " << e.second << endl;
        e.first = max(e.first, f.first);
        e.second = min(e.second, f.second);
        //if (x0-i*e.second > p) cout << x0 << "!!" << e.first << " " << e.second << endl;
        //cout << x0 << " " << y0 << " " << e.first << " " << e.second << endl;
        if (e.first > e.second) continue;
        y0 += e.second*(i+1), x0 -= e.second * i;
        //cout << A << " " << B << " " << C << " " << x0 << " " << y0 << endl;
        //if (x0 + y0 > ans) cout << A << " " << B << " " << C << " " << x0 << " " << y0 << " " << p << endl;
        ans = max(ans, x0+y0);
        //cout << 123 << endl;
    }
}
int32_t main(){
    int l, r;
    cin >> n >> l >> r >> k;
    p = ((r-l)%n+n)%n + 1;
    t = n-p;
    //cout << p << " " << t << endl;
    k -= p;
    if (k < 0){
        cout << -1;
        return 0;
    }
    if (n <= 5e5){
        sort_a(0);
        //else sort_x();
        k++;
        sort_a(1);
    }
    else{
        sort_x(0);
        k++;
        sort_x(1);
    }
    if (ans < 0) cout << -1;
    else cout << ans;

}