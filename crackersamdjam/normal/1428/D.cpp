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
const int MM = 2e5+5;

int t, n, a[MM], b[MM];

int main(){
	scan(n);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
	}
	vector<pair<int, int>> ans;
	vector<int> on3, last, off;
	int r = 1, no = 0;
	for(int i = n; i; i--){
		if(a[i] == 0){

		}
		else if(a[i] == 1){
			on3.emplace_back(i);
			b[i] = r++;
			ans.emplace_back(i, b[i]);
		}
		else if(a[i] == 2){
			if(size(on3)){
				//add
				int j = on3.back(); on3.pop_back();
				b[i] = b[j];
				ans.emplace_back(i, b[i]);
				last.emplace_back(i);
			}
			else no = 1;
		}
		else if(a[i] == 3){
			if(size(on3) or size(last)){
				//add	
				int j;
				if(size(last)){
					j = last.back(); last.pop_back();
				}
				else{
					j = on3.back(); on3.pop_back();
				}
				b[i] = r++;
				ans.emplace_back(j, b[i]);
				ans.emplace_back(i, b[i]);
				last.emplace_back(i);
			}
			else no = 1;
		}
	}
	if(r-1 > n)
		no = 1;
	if(no){
		print(-1);
	}
	else{
		print(size(ans));
		for(auto i: ans){
			// print(i.first, i.second);
			print(n+1-i.second, i.first);
		}
	}
}