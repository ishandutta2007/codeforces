/*
	author: DPair
	language: C++11

	description:
	
*/
#include <cstdio>
namespace IO{
	#define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 23, stdin), SS == TT) ? EOF : *SS++)
	char BB[1 << 23], *SS = BB, *TT = BB;
	template <typename T>
	inline void read(T &x){
		x = 0;int fu = 1;
		char c = getcha();
		while(c > 57 || c < 48){
			if(c == 45) fu = -1;
			c = getcha();
		}
		while(c <= 57 && c >= 48){
			x = x * 10 + c - 48;
			c = getcha();
		}
		x *= fu;
	}
	template <typename T, typename ...Args>
	inline void read(T &x, Args &...args){
		read(x);read(args...);
	}
	char out[1 << 22], *Out = out;
	#define flush() fwrite(out, 1, Out - out, stdout)
	inline void putcha(char x) {*Out++ = x;if(Out - out >= (1 << 22)) flush(), Out = out;}
	template <typename T>
	inline void fprint(T x){
		if(x < 0) putcha(45), x = -x;
		if(x > 9) fprint(x / 10);
		putcha(x % 10 + 48);
	}
	template <typename T>
	inline void print(T x){fprint(x);putcha(10);}
	inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
	inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
	template <typename T, typename ...Args>
	inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
	template <typename T>
	inline void sprint(T x){fprint(x);putcha(32);}
	template <typename T, typename ...Args>
	inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
	class AutoFlush{
		public:
			~AutoFlush(){flush();}
	}__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
const LL MOD = 1e9+7;
LL dp[35][35][2];
int main(){
	int n;read(n);
	dp[30][0][1] = 1;
	for (int i = 29;~i;-- i){
		for (int j = 0;j <= 30;++ j){
			dp[i][j][0] = (dp[i][j][0] + (1ll << j) * dp[i + 1][j][0]) % MOD;
			dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i + 1][j][0]) % MOD;
			LL t1 = 1, t2 = 0;
			if(j) t1 = t2 = (1ll << (j - 1));
			if((n >> i) & 1){
				dp[i][j][0] = (dp[i][j][0] + t1 * dp[i + 1][j][1]) % MOD;
				dp[i][j][1] = (dp[i][j][1] + t2 * dp[i + 1][j][1]) % MOD;
				dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i + 1][j][1]) % MOD;
			}
			else dp[i][j][1] = (dp[i][j][1] + t1 * dp[i + 1][j][1]) % MOD;
		}
	}
	LL ans = 0;
	for (int i = 0;i <= 30;++ i) ans = (ans + dp[0][i][0] + dp[0][i][1]) % MOD;
	print(ans);
}