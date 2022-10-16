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
using ll = __int128;

string s = "codeforces";
ll cnt[11];
ll k;

int main(){
	scan(k);
	for(int i = 0; i < 10; i++)
		cnt[i] = 1;
	
	while(1){
		ll v = 1;
		for(int i = 0; i < 10; i++)
			v *= cnt[i];
		if(v >= k)
			break;
		
		ll minn = LLONG_MAX;
		int id = -1;
		for(int i = 0; i < 10; i++){
			if(cnt[i] < minn){
				minn = cnt[i];
				id = i;
			}
		}
		cnt[id]++;
	}
	for(int i = 0; i < 10; i++){
		while(cnt[i]--)
			pc(s[i]);
	}
}