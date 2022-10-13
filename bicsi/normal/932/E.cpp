#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9 + 7;
struct ModInt {
    int x;
    ModInt(int x = 0) : x(x) {}
    ModInt operator+(const ModInt& oth) const { 
        int ret = x + oth.x;
        if (ret >= kMod) ret -= kMod;
        return ret;
    }
    ModInt operator-(const ModInt& oth) const { 
        int ret = x - oth.x;
        if (ret < 0) ret += kMod;
        return ret;
    }
    ModInt operator*(const ModInt& oth) const { 
        return 1LL * x * oth.x % kMod;
    }
    int Get() const { 
        return x;
    }
};
ModInt lgpow(ModInt b, int e) {
    ModInt r = 1;
    while (e) {
        if (e % 2)
            r = r * b;
        e /= 2;
        b = b * b;
    }
    return r;
}
ModInt inv(ModInt oth) {
    static ModInt mem[20000];
    if (oth.x + 10000 < 20000 && oth.x + 10000 >= 0) {
        auto& ret = mem[oth.x + 10000];
        if (ret.x != 0) return ret;
        return ret = lgpow(oth, kMod - 2);
    }
    return lgpow(oth, kMod - 2);
}

using Poly = vector<ModInt>;
Poly Interpolate(vector<ModInt> x, vector<ModInt> y) {
	int n = x.size();
	Poly res(n), temp(n);
	for (int k = 0; k < n; ++k)
	  for (int i = k + 1; i < n; ++i)
		y[i] = (y[i] - y[k]) * inv(x[i] - x[k]);
	ModInt last = 0; temp[0] = 1;
	for (int k = 0; k < n; ++k)
	for (int i = 0; i < n; ++i) {
		res[i] = res[i] + y[k] * temp[i];
		swap(last, temp[i]);
		temp[i] = temp[i] - last * x[k];
	}
	return res;
}
ModInt Eval(Poly P, ModInt x) {
    reverse(P.begin(), P.end());
    ModInt ans = 0;
    for (auto y : P)
        ans = ans * x + y;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x;
    
    vector<ModInt> pows(5010);
    for (int i = 0; i < (int)pows.size(); ++i) {
        ModInt now = 1;
        for (int j = 0; j < x; ++j) {
            now = now * i;
        }
        pows[i] = now;
    }
    

    vector<vector<ModInt>> choose(5010, vector<ModInt>(5010));
    for (int i = 0; i < (int)choose.size(); ++i) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
        }
    }
/*
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= i; ++j) {
            cerr << choose[i][j].Get() << " ";
        }
        cerr << endl;
    }
*/
    auto Brut = [&](int i) {
        ModInt ans = 0;
        for (int j = 1; j <= i; ++j) {
            ans = ans + choose[i][j] * pows[j];
        }
        return ans;
    };
    
/*
    if (n <= x) {
        cout << Brut(n).Get() << " ";
    } else {
        ModInt ans = 1;
        for (int i = 0; i < x; ++i) {
            ans = ans * (n + i);
        }
        int e = (n - x);
        ModInt b = 2;
        while (e) {
            if (e % 2) ans = ans * b;
            b = b * b;
            e /= 2;
        }
        cout << ans.Get() << endl;
        cerr << Brut(n).Get() << endl;
    }

    return 0;

    for (int i = 1; i <= 10; ++i) {
        cerr << Brut(i).Get() << " ";
    }    
    cerr << endl;
    return 0;
*/

    vector<ModInt> X(x + 5), Y(x + 5);
    for (int i = 1; i < x + 5; ++i) {
        X[i] = i; Y[i] = Brut(i) * inv(lgpow(2, i));
    }

//    for (auto x : X) cerr << x.Get() << " "; cerr << endl;
//    for (auto y : Y) cerr << y.Get() << " "; cerr << endl;

    auto poly = Interpolate(X, Y);
//    for (auto x : poly) cerr << x.x << " "; cerr << endl;
    
//    for (int i = 0; i < (int)X.size(); ++i) {
//        cerr << X[i].Get() << " " << Y[i].Get() << endl;
//        assert(Eval(poly, X[i]).Get() == Y[i].Get());
//    }

//    for (int i = 0; i <= 100; ++i) {
//        cerr << Brut(i).Get() << " " << (Eval(poly, i) * lgpow(2, i)).Get() << endl;
//    }
    
    cout << (Eval(poly, n) * lgpow(2, n)).Get() << endl;

    return 0;
}