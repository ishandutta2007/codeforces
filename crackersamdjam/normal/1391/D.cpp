#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+5;

int n, m, dp[MM][8];
char s[3][MM];

bool on(int mask, int j){
	return (mask&(1<<j)) > 0;
}

int main(){
	scan(n, m);
	if(n >= 4 and m >= 4){
		print(-1);
		return 0;
	}
	if(n == 1 or m == 1){
		print(0);
		return 0;
	}
	if(n > m){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				s[j][i] = gc;
			}
			gc;
		}
		swap(n, m);
	}
	else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				s[i][j] = gc;
			}
			gc;
		}
	}
	// print(n, m);
	for(int i = 0; i < n; i++){
		// printf("%d, %s\n", i, s[i]);
		for(int j = 0; j < m; j++)
			s[i][j] -= '0';
	}

	if(n == 2){
		memset(dp, 0x3f, sizeof dp);
		for(int cur = 0; cur < 4; cur++){
			int c = (on(cur, 0) != s[0][0]) + (on(cur, 1) != s[1][0]);
			dp[0][cur] = c;
		}
		int ans = 1e9;
		for(int i = 1; i < m; i++){
			for(int pre = 0; pre < 4; pre++){
				for(int cur = 0; cur < 4; cur++){
					int va = on(pre, 0)^on(pre, 1)^on(cur, 0)^on(cur, 1);
					int c = (on(cur, 0) != s[0][i]) + (on(cur, 1) != s[1][i]);
					// if(i == 2 and cur == 1){
						// cout<<"c "<<(int)on(cur, 0)<<' '<<(int)s[i][0]<<' '<<(int)on(cur, 1)<<' '<<(int)s[i][1]<<endl;
					// }
					if(va){
						dp[i][cur] = min(dp[i][cur], dp[i-1][pre] + c);
					}
					if(i == m-1)
						ans = min(ans, dp[i][cur]);
				}
			}
		}
		// for(int i = 0; i < m; i++){
		// 	for(int cur = 0; cur < 4; cur++)
		// 		cout<<dp[i][cur]<<' ';
		// 	cout<<endl;
		// }

		if(ans == 1e9)
			ans = -1;
		print(ans);
		return 0;
	}

	memset(dp, 0x3f, sizeof dp);
	for(int cur = 0; cur < 8; cur++){
		int c = (on(cur, 0) != s[0][0]) + (on(cur, 1) != s[1][0]) + (on(cur, 2) != s[2][0]);
		dp[0][cur] = c;
	}
	int ans = 1e9;
	for(int i = 1; i < m; i++){
		for(int pre = 0; pre < 8; pre++){
			for(int cur = 0; cur < 8; cur++){
				int va = on(pre, 0)^on(pre, 1)^on(cur, 0)^on(cur, 1);
				int vb = on(pre, 1)^on(pre, 2)^on(cur, 1)^on(cur, 2);
				int c = (on(cur, 0) != s[0][i]) + (on(cur, 1) != s[1][i]) + (on(cur, 2) != s[2][i]);
				if(va and vb){
					dp[i][cur] = min(dp[i][cur], dp[i-1][pre] + c);
				}
				if(i == m-1)
					ans = min(ans, dp[i][cur]);
			}
		}
	}
	// for(int i = 0; i < m; i++){
		// for(int cur = 0; cur < 8; cur++)
			// cout<<dp[i][cur]<<' ';
		// cout<<endl;
	// }

	if(ans == 1e9)
		ans = -1;
	print(ans);
}