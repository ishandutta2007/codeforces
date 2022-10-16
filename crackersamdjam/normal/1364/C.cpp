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

int n, a[MM], b[MM];
vector<int> v;
priority_queue<int, vector<int>, greater<int>> q;
bool used[MM];
int l = 0;

int main(){
	scan(n);
	for(int i = 0; i < 3*n; i++)
		q.push(i);
	for(int i = 0; i < n; i++){
		scan(a[i]);
		v.emplace_back(i);
		while(q.top() < a[i]){
			int j = v.back(); v.pop_back();
			b[j] = q.top();
			q.pop();
		}
	}
	while(v.size()){
		int j = v.back(); v.pop_back();
		b[j] = n+5;
	}

	for(int i = 0; i < n; i++){
		used[b[i]] = 1;
		while(used[l])
			l++;
		if(l != a[i]){
			print(-1);
			return 0;
		}
	}

	for(int i = 0; i < n; i++)
		printf("%d ", b[i]);
}