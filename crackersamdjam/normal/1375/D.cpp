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
const int MM = 1005;

int t, n, a[MM], cnt[MM];
multiset<int> st;
vector<int> out;

int val(){
	int hi = 0;
	while(st.count(hi))
		hi++;
	return hi;
}

void go(int i){
	int tmp = val();
	st.erase(st.lower_bound(a[i]));
	a[i] = tmp;
	st.insert(tmp);

	out.emplace_back(i);
}

int main(){
	scan(t);
	while(t--){
		out.clear();
		st.clear();
		scan(n);
		for(int i = 0; i < n; i++){
			scan(a[i]);
			st.insert(a[i]);
		}
		while(val() < n){
			int v = val();
			go(v);
		}
		int r = n-1;
		while(r >= 0){
			while(r >= 0 and a[r] == r)
				r--;
			if(r >= 0){
				//fix this one by switching places
				int j = -1;
				for(int k = 0; k < n; k++){
					if(a[k] == r){
						j = k;
						break;
					}
				}
				assert(~j);
				go(j);
				go(r);
			}
			while(val() < n){
				int v = val();
				go(v);
			}
		}

		print(out.size());
		for(int i: out)
			printf("%d ", i+1);
		pc(10);
		// cout<<"after"<<endl;
		// for(int i = 0; i < n; i++)
			// printf("%d ", a[i]);
		// pc(10);
		assert(is_sorted(a, a+n));
		assert((int)out.size() <= 2*n);
	}
}