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
using ll = long long;
const int MM = 1e5+5, LIM = 10000;

// mt19937 g(chrono::steady_clock::now().time_since_epoch().count());

int n, cnt, in;
bool np[MM], done[MM];
vector<int> v;

// #define wtf
#ifdef wtf
int SECRET = 1, IN, DONE[MM];
#endif

int ask(string s, ll x){
	cnt++;
	cout<<s<<' '<<x<<endl;
	if(s == "B"){
		for(ll j = x; j <= n; j += x){
			if(!done[j]){
				in--;
				done[j] = 1;
			}
		}
	}
#ifdef wtf
	int ret = 0;
	for(ll j = x; j <= n; j += x)
		ret += !DONE[j];
	if(s == "B"){
		for(ll j = x; j <= n; j += x){
			if(!DONE[j] and j != SECRET){
				IN--;
				DONE[j] = 1;
			}
		}
	}
	return ret;
#endif
	int res;
	cin>>res;
	return res;
}

ll x = 1;

void go(int l, int r){
	if(l > r)
		return;
	int m = (l+r)/2;
	for(int i = l; i <= m; i++){
		ask("B", v[i]);
	}
	int res = ask("A", 1);
	// cerr<<"cmp "<<in<<' '<<res<<endl;
	if(res != in){
		for(; l <= m; l++){	
			// ask("B", v[l]);
			int res = ask("A", v[l]);
			// cerr<<"found "<<v[l]<<' '<<res<<endl;
			if(res){
				x *= v[l];
				return;
			}
		}
	}
	else go(m+1, r);
}

int main(){
	cin>>n;
	in = n;

#ifdef wtf
	cin>>SECRET;
#endif

	for(int i = 2; i <= n; i++){
		if(np[i]) continue;
		v.emplace_back(i);
		for(int j = i+i; j <= n; j += i)
			np[j] = 1;
	}

	// int SQRT = ceil(sqrtl(n))+1;
	const int SQRT = 317;
	// const int SQRT = 4;

	vector<int> lo, hi;
	for(int i: v)
		if(i < SQRT)
			lo.emplace_back(i);
		else
			hi.emplace_back(i);

	v = hi;
	go(0, (int)size(v)-1);

	v = lo;
	for(int i = 0; i < (int)size(v); i++){
		ll mx = 1;
		ask("B", v[i]);
		for(ll j = v[i]; j <= n; j *= v[i]){
			int res = ask("A", j);
			if(res) mx = j;
		}
		x *= mx;
	}

#ifdef wtf
	cerr<<"SQRT "<<SQRT<<endl;
	cerr<<"cnt "<<cnt<<endl;
	cerr<<"C "<<x<<endl;
	assert(x == SECRET);
#endif

	assert(cnt+1 <= LIM);
	assert(x <= n);
	cout<<"C "<<x<<endl;
}