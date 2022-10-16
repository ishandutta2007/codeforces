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

int t, n, m, a, b, s[55][55], cnta[55], cntb[55];

int main(){
	scan(t);
	while(t--){
		scan(n, m, a, b);
		memset(s, 0, sizeof s);
		memset(cnta, 0, sizeof cnta);
		memset(cntb, 0, sizeof cntb);
		set<pair<int, int>> st;
		for(int j = 0; j < m; j++){
			st.insert({0, j});
		}
		for(int i = 0; i < n; i++){
			for(int tt = 0; tt < a; tt++){
				auto rm = *st.begin();
				st.erase(rm);
				int j = rm.second;
				s[i][j] = 1;
				cntb[j]++;
				rm.first++;
				st.insert(rm);
			}
		}

		bool no = 0;
		for(int i = 0; i < m; i++){
			if(cntb[i] != b)
				no = 1;
		}
		if(no){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				printf("%d", s[i][j]);
			}
			pc(10);
		}
	}	
	

	
	return 0;
}