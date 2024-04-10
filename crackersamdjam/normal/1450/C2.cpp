#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 305, o = 3;

int t, n;
char s[MM][MM];
int k, ans;

void go(int i, int j){
	s[i][j] = s[i][j] == 'X' ? 'O' : 'X';
	ans++;
}
void out(){
	for(int i = o; i < n+o; i++){
		printf("%s\n", s[i]+o);
	}
}

int main(){
	scan(t);
	while(t--){
		memset(s, 0, sizeof s);
		scan(n);
		k = ans = 0;
		for(int i = o; i < n+o; i++){
			scanf("%s", s[i]+o);
			for(int j = o; j < n+o; j++){
				k += s[i][j] != '.';
			}
		}

		for(int r = 0; r < 3; r++){
			ans = 0;
			for(int i = o; i < n+o; i++){
				for(int j = o; j < n+o; j++){
					if((i+j+r)%3 == 0){
						if(s[i][j] == 'X')
							ans++;
					}
					else if((i+j+r)%3 == 1){
						if(s[i][j] == 'O')
							ans++;
					}
				}
			}
			// print(ans, k/3);
			if(ans <= k/3){
				for(int i = o; i < n+o; i++){
					for(int j = o; j < n+o; j++){
						if((i+j+r)%3 == 0){
							if(s[i][j] == 'X')
								go(i, j);
						}
						else if((i+j+r)%3 == 1){
							if(s[i][j] == 'O')
								go(i, j);
						}
					}
				}
				out();
				break;
			}
		}
		// print(ans, k/3);
		// assert(ans <= k/3);
		// out();
		// cout<<"-------------------------"<<endl;
	}
}