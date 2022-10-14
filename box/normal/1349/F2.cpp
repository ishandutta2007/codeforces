#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 998244353;

typedef uint32_t u32;
typedef uint64_t u64;

u64 dp1[100005], dp2[100005], ans[100005], rans[100005];
u64 fac[100005], inv[100005], ifa[100005], tp[100005], rtp[100005];

u32 to(u32 a) {
	return (u32)((((u64) a) << 32) % 998244353);
}

inline u32 redc(u64 a) {
	u32 b = (u32)a * 998244351;
	u64 c = a + (u64)b * 998244353;
	return (u32)(c >> 32);
}

#define Load(ptr) (_mm256_loadu_si256((__m256i*)(ptr)))
#define Store(ptr, __A) _mm256_storeu_si256((__m256i*)(ptr), __A)

__attribute__((always_inline)) __m256i redc(__m256i a) {
	__m256i b = _mm256_mul_epu32(a, _mm256_set1_epi32(998244351));
	__m256i c = _mm256_add_epi64(a, _mm256_mul_epu32(b, _mm256_set1_epi32(998244353)));
	return _mm256_srli_epi64(c, 32);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	fac[0] = fac[1] = inv[0] = inv[1] = ifa[0] = ifa[1] = 1;
	iter(i, 2, n+2) {
		fac[i] = 1ll * fac[i-1] * i % MOD;
		inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
		ifa[i] = 1ll * ifa[i-1] * inv[i] % MOD;
	}
	rep(i, n+2) {
		tp[i] = to(i);
		rtp[n+2-i] = tp[i];
	}
	dp1[0] = tp[1];
	dp2[0] = tp[1];
	int cur = 1;
	rep1(j, n) {
		if(j != 1) {
			int th=j/2;
			if(cur == 1) {
				int i=1,rv=n+2-j+1;
				for(; i+4<=th; i+=4, rv+=4) {
					Store(&dp2[i], 
						redc(_mm256_add_epi64(
							_mm256_mul_epu32(Load(&tp[i+1]),Load(&dp1[i])),
							_mm256_mul_epu32(Load(&rtp[rv]),Load(&dp1[i-1]))
						))
					);
				}
				for(; i<=th; i++)
					dp2[i] = redc(1ull*tp[i+1]*dp1[i]+1ll*tp[j-i]*dp1[i-1]);
				dp2[th]=dp2[th-1];
				cur = 2;
			} else {
				int i=1,rv=n+2-j+1;
				for(; i+4<=th; i+=4, rv+=4) {
					Store(&dp1[i], 
						redc(_mm256_add_epi64(
							_mm256_mul_epu32(Load(&tp[i+1]),Load(&dp2[i])),
							_mm256_mul_epu32(Load(&rtp[rv]),Load(&dp2[i-1]))
						))
					);
				}
				for(; i<=th; i++)
					dp1[i] = redc(1ull*tp[i+1]*dp2[i]+1ll*tp[j-i]*dp2[i-1]);
				cur = 1;
			}
		}
		u32 q = to(ifa[j]);
		__m256i Q = _mm256_set1_epi32(q);
		if(cur == 1) {
			int i=0, rv=n-j+1;
			for(; i+4<=j/2-1; i+=4, rv+=4) {
				__m256i t = redc(_mm256_mul_epu32(Load(&dp1[i]), Q));
				Store(&ans[i], _mm256_add_epi64(Load(&ans[i]), t));
				Store(&rans[rv], _mm256_add_epi64(Load(&rans[rv]), t));
			}
			for(; i<=j/2-1; i++) {
				u32 t = redc(1ull*dp1[i]*q);
				ans[i] += t;
				ans[j-1-i] += t;
			}
			ans[j/2] += redc(1ull*dp1[j/2]*q);
			ans[j/2] -= (ans[j/2] < MOD ? 0 : MOD);
		} else {
			int i=0, rv=n-j+1;
			for(; i+4<=j/2-1; i+=4, rv+=4) {
				__m256i t = redc(_mm256_mul_epu32(Load(&dp2[i]), Q));
				Store(&ans[i], _mm256_add_epi64(Load(&ans[i]), t));
				Store(&rans[rv], _mm256_add_epi64(Load(&rans[rv]), t));
			}
			for(; i<=j/2-1; i++) {
				u32 t = redc(1ull*dp2[i]*q);
				ans[i] += t;
				ans[j-1-i] += t;
			}
		}
	}
	rep(i, n) cout << redc(redc(1ull * ((ans[i]+rans[n-i])%MOD) * to(fac[n]))) << " \n"[i==n-1];
}