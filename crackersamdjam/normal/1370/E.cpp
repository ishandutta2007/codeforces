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

char s[MM], t[MM];
int n, cs, ct;

int main(){
	scanf("%d %s %s", &n, s, t);
	for(int i = 0; i < n; i++){
		s[i] -= '0';
		t[i] -= '0';
		cs += s[i];
		ct += t[i];
	}
	if(ct != cs){
		print(-1);
		return 0;
	}
	int on[2] = {0, 0}, cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			if(on[s[i]]){
				on[s[i]]--;
				on[t[i]]++;
				//swap
			}
			else{
				cnt++;
				on[t[i]]++;
				//add
			}
		}
	}
	print(cnt);
}