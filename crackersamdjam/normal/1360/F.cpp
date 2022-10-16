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

int t, n, m;
char s[55][55];
string ans;
set<string> vis;

void go(int i, string ss){
	// cout<<"go "<<i<<' '<<ss<<endl;
	if(ans.size() > 0 || vis.count(ss))
		return;
	vis.insert(ss);
	if(i == m){
		for(int j = 0; j < n; j++){
			int d = 0;
			for(int k = 0; k < m; k++)
				d += (s[j][k] != ss[k]);
			if(d > 1)
				return;
		}
		ans = ss;
		return;
	}
	for(int j = 0; j < n; j++){
		go(i+1, ss+s[j][i]);
	}
}

int main(){
	scan(t);
	while(t--){
		vis.clear();
		ans = "";
		scan(n, m);
		for(int i = 0; i < n; i++)
			scanf("%s", s[i]);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int d = 0;
				for(int k = 0; k < m; k++){
					d += (s[i][k] != s[j][k]);
				}
				if(d > 2)
					goto out;
			}
		}
		go(0, "");
		out:;
		if(ans.size()){
			for(auto i: ans)
				pc(i);
			pc(10);
		}
		else
			print(-1);
	}

	
	return 0;
}