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
const int MM = 1e5+5;

int n, a[MM], l, b[MM];
vector<int> ord;

int main(){
	scan(n);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	sort(a, a+n, greater<int>());

	if(n%2 == 1){
		for(int i = 2; i < n; i += 2)
			ord.emplace_back(i);

		ord.emplace_back(0);
		for(int i = 3; i < n-1; i += 2)
			ord.emplace_back(i);
		
		ord.emplace_back(1);
	}
	else{
		for(int i = 2; i < n; i += 2)
			ord.emplace_back(i);
		
		ord.emplace_back(0);
		ord.emplace_back(n-1);

		for(int i = 3; i < n-1; i += 2)
			ord.emplace_back(i);
		
		ord.emplace_back(1);
	}

	for(int i = 0; i < n; i++){
		b[ord[i]] = a[i];
	}
	int ans = 0;
	for(int i = 1; i < n-1; i++){
		if(b[i] < b[i-1] and b[i] < b[i+1])
			ans++;
	}
	print(ans);
	for(int i = 0; i < n; i++)
		printf("%d ", b[i]);
}