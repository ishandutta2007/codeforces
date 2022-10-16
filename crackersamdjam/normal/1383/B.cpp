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
const int MM = 1e5+5;

int t, n, a[MM], b[MM], dp[MM][2][2][2]; //rem, who to move, vala, valb

int main(){
	scan(t);
	while(t--){
		memset(b, 0, sizeof b);
		scan(n);
		for(int i = 0; i < n; i++){
			scan(a[i]);
			for(int j = 0; j < 31; j++){
				if(a[i]&(1<<j)){
					b[j]++;
				}
			}
		}
		int last = n&1;
		//if 1, first player last
		// 1 last can force 0
		for(int j = 30; j >= 0; j--){
			if(!b[j]) continue;
			dp[0][0][1][0] = 1;
			dp[0][0][0][1] = -1;
			dp[0][1][1][0] = -1;
			dp[0][1][0][1] = 1;
			// cout<<"j "<<j<<endl;
			// for(int cc = 0; cc < 2; cc++)
			// 		for(int aa = 0; aa < 2; aa++)
			// 			for(int bb = 0; bb < 2; bb++)
			// 				printf("%d ", dp[0][cc][aa][bb]);
			// pc(10);

			for(int i = 1; i <= b[j]; i++){
				for(int cc = 0; cc < 2; cc++){
					for(int aa = 0; aa < 2; aa++){
						for(int bb = 0; bb < 2; bb++){
							int canwin = (dp[i-1][cc^1][aa^(cc == 0)][bb^(cc == 1)] == -1); //take
								// or (cc == last and dp[i-1][cc][aa^(cc != 0)][bb^(cc != 1)] == 1); //force other to take
							int candraw = (dp[i-1][cc^1][aa^(cc == 0)][bb^(cc == 1)] == 0);
								// or (cc == last and dp[i-1][cc][aa^(cc != 0)][bb^(cc != 1)] == 0);
							if(canwin)
								dp[i][cc][aa][bb] = 1;
							else if(candraw)
								dp[i][cc][aa][bb] = 0;
							else
								dp[i][cc][aa][bb] = -1;
							// printf("%d ", dp[i][cc][aa][bb]);
						}
					}
				}
				// pc(10);
			}
			int ans = dp[b[j]][0][0][0];
			// cout<<"ans "<<ans<<endl;
			for(int i = 0; i <= b[j]; i++)
				memset(dp[i], 0, sizeof dp[i]);
			if(ans){
				if(ans == 1)
					puts("WIN");
				else{
					int rem = (n-b[j])%2;
					if(rem)
						puts("WIN");
					else
						puts("LOSE");
				}
				goto out;
			}
		}
		puts("DRAW");

		out:;
	}
}