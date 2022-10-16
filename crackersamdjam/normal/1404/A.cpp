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
const int MM = 3e5+5;

int t, n, k;
char s[MM];

int main(){
	scan(t);
	while(t--){
		int no = 0;
		scan(n, k);
		scanf("%s", s);


		for(int i = 0; i < k; i++){
			set<char> st;
			for(int j = i; j < n; j += k){
				st.insert(s[j]);
			}
			if(st.count('?'))
				st.erase('?');
			if(st.size() > 1)
				no = 1;
			if(st.size()){
				char c = *st.begin();
				for(int j = i; j < n; j += k)
					s[j] = c;
			}
		}

		int a = 0, b = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '1')
				a++;
			else if(s[i] == '0')
				b++;

			if(i >= k){
				if(s[i-k] == '1')
					a--;
				else if(s[i-k] == '0')
					b--;
			}

			if(a*2 > k or b*2 > k)
				no = 1;
		}
		puts(no ? "NO" : "YES");
	}
}