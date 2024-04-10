#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2e4 + 10;

int mod_add(int a, int b) {
    int sum = a + b;
    return sum >= MOD ? sum - MOD : sum;
}
 
int mod_sub(int a, int b) {
    int diff = a - b;
    return diff < 0 ? diff + MOD : diff;
}
 
int mod_mul(int a, int b, int m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return (long long) a * b % m;
#endif
    uint64_t x = (uint64_t) a * b;
    unsigned x_high = x >> 32, x_low = (unsigned) x;
    unsigned div, mod;
    asm(
        "divl %4; \n\t"
        : "=a" (div), "=d" (mod)
        : "d" (x_high), "a" (x_low), "r" (m)
    );
    return mod;
}
 
long long mod_inv(long long a, long long m = MOD) {
    return a == 1 ? 1 : m - mod_inv(m % a, a) * m / a;
}
 
long long mod_pow(long long a, long long p, long long m = MOD) {
    long long result = 1;
 
    while (p > 0) {
        if (p & 1)
            result = mod_mul(result, a, m);
 
        a = mod_mul(a, a, m);
        p >>= 1;
    }
 
    return result;
}

namespace NTT {
    vector<int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    int root;
 
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }
 
    int round_up_power_two(int n) {
        assert(n > 0);
 
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return n;
    }
 
    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }
 
    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<int> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        int order = MOD - 1;
        max_size = 1;
 
        while (order % 2 == 0) {
            order /= 2;
            max_size *= 2;
        }
 
        root = 2;
 
        // Find a max_size-th primitive root of MOD.
        while (!(mod_pow(root, max_size) == 1 && mod_pow(root, max_size / 2) != 1))
            root++;
    }
 
    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();
 
        if ((int) roots.size() >= n)
            return;
 
        int length = get_length(roots.size());
        roots.resize(n);
 
        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            int z = mod_pow(root, max_size >> (length + 1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = mod_mul(roots[i], z);
            }
 
            length++;
        }
    }
 
    void fft_iterative(int N, vector<int> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);
        assert(N <= max_size);
 
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    int even = values[start + i];
                    int odd = mod_mul(values[start + n + i], roots[n + i]);
                    values[start + n + i] = mod_sub(even, odd);
                    values[start + i] = mod_add(even, odd);
                }
    }
 
    const int FFT_CUTOFF = 150;
 
    vector<int> mod_multiply(vector<int> left, vector<int> right, bool trim = true) {
        int n = left.size();
        int m = right.size();
 
        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] < MOD);
 
        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] < MOD);
 
        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) left[i] * right[j];
 
                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }
 
            for (int i = 0; i < (int) result.size(); i++)
                if (result[i] >= (uint64_t) MOD)
                    result[i] %= MOD;
 
            if (trim) {
                while (!result.empty() && result.back() == 0)
                    result.pop_back();
            }
 
            return vector<int>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);
 
        bool equal = left == right;
        fft_iterative(N, left);
 
        if (equal)
            right = left;
        else
            fft_iterative(N, right);
 
        int inv_N = mod_inv(N);
 
        for (int i = 0; i < N; i++)
            left[i] = mod_mul(mod_mul(left[i], right[i]), inv_N);
 
        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
 
        if (trim) {
            while (!left.empty() && left.back() == 0)
                left.pop_back();
        }
 
        return left;
    }
 
    vector<int> power(const vector<int> &v, int exponent) {
        assert(exponent >= 0);
        vector<int> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);
 
            if (exponent & 1 << k)
                result = mod_multiply(result, v);
        }
 
        return result;
    }
};

int n, k, a[MAXN], _a[MAXN];

vector<int> go(int l, int r){
	int ln = r-l;
	if (r - l == 1){
		vector<int> ret(ln+1, 0);
		ret[0] = 1;
		ret[1] = a[l];
		return ret;
	}

	int mid = l+r>>1;
	vector<int> resL = go(l, mid);
	vector<int> resR = go(mid, r);
	vector<int> res = NTT::mod_multiply(resL, resR, false);
	return res;
}

int solve(){
	for (int i = 0; i < n; i++) a[i] = (a[i]%MOD+MOD)%MOD;
	vector res = go(0, n);
	return res[k];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	memcpy(_a, a, sizeof(a));
	int te; cin >> te;
	while (te--){
		int type; cin >> type;
		if (type == 1){
			memcpy(a, _a, sizeof(a));
			int q, i, d; cin >> q >> i >> d, i--;
			a[i] = d;
			for (int i = 0; i < n; i++) a[i] = q - a[i];
			cout << solve() << "\n";
		}
		else{
			memcpy(a, _a, sizeof(a));
			int q, l, r, d; cin >> q >> l >> r >> d, l--;
			for (int i = l; i < r; i++) a[i] += d;
			for (int i = 0; i < n; i++) a[i] = q - a[i];
			cout << solve() << "\n";
		}
	}
	return 0;
}