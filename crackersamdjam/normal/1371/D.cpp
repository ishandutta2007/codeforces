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

int t, n, k, a[305][305];

int main(){
	scan(t);
	while(t--){
		memset(a, 0, sizeof a);
		scan(n, k);
		int each = k/n, rem = k%n;
		for(int i = 0; i < n; i++){
			int j = i;
			for(int z = 0; z < each+(i<rem); z++){
				a[i][j] = 1;
				j++;
				j %= n;
			}
		}
		int maxi = 0, mini = n, maxj = 0, minj = n;
		for(int i = 0; i < n; i++){
			int sum = 0;
			for(int j = 0; j < n; j++)
				sum += a[i][j];
			maxi = max(maxi, sum);
			mini = min(mini, sum);
		}
		for(int j = 0; j < n; j++){
			int sum = 0;
			for(int i = 0; i < n; i++)
				sum += a[i][j];
			maxj = max(maxj, sum);
			minj = min(minj, sum);
		}
		print((maxi-mini)*(maxi-mini) + (maxj-minj)*(maxj-minj));

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				printf("%d", a[i][j]);
			pc(10);
		}
	}
}