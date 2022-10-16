#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;

//mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 g((uint64_t) new char);
mt19937_64 g(0);
int randint(int l, int r){return uniform_int_distribution<int>(l, r)(g);}
long long randl(long long l, long long r){return uniform_int_distribution<long long>(l, r)(g);}
double randf(double l, double r){return uniform_real_distribution<double>(l, r)(g);}

int n, sum, ans, cnt;

#define T2
#if defined(T2) && defined(LOCAL)
#define TEST
#endif
#ifdef TEST
vector<int> arr = {5, 2, 7, 3, 5, 6};

int query2(int w){
	int ret = 1, s = 0;
	for(auto i: arr){
		if(i > w) return 0;
		int add = i+(s>0);
		if(s+add <= w){
			s += add;
		}
		else{
			ret++;
			s = i;
		}
	}
	return ret;
}

#endif

map<int, int> cache;
int query(int w){
	if(cache.count(w)) return cache[w];
	cnt++;
	if(cnt > n+30){
		pr("too many");
		abort();
	}
#ifdef TEST
	int ret = 1, s = 0;
	for(auto i: arr){
		if(i > w) return 0;
		int add = i+(s>0);
		if(s+add <= w){
			s += add;
		}
		else{
			ret++;
			s = i;
		}
	}
	return cache[w] = ret;
#endif
	cout<<"? "<<w<<endl;
	int x; cin>>x;
	return cache[w] = x;
}

int main(int argc, char *args[]){
	int seed = argc > 1 ? atoi(args[1]) : 0;
	g = mt19937_64(seed);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

#ifdef TEST
	// n = randint(1, 2000);
	// arr.resize(n);
	// for(int &i: arr){
	// 	i = randint(1, 2000);
	// }
	n = (int)size(arr);
#else
	cin>>n;
#endif
	int l = 1, r = 2000*n;
	while(l <= r){
		int m = l+r>>1;
		if(query(m+n-1) == 1)
			r = m-1;
		else
			l = m+1;
	}
	sum = l;
	ans = sum+n-1;

	for(int h = 1; h <= n; h++){
		int w = (sum+n-1)/h;
		int q = query(w);
		if(!q) continue;
		ans = min(ans, w*q);
	}

	cout<<"! "<<ans<<'\n';
	pr("cnt", cnt);

#ifdef TEST
	{
		int realans = INT_MAX;
		int ssum = accumulate(all(arr), 0);
		for(int i = 1; i <= ssum+n-1; i++){
			int q = query2(i);
			if(q){
				realans = min(realans, q*i);
			}
		}
		pr("ans", realans, ans);
		assert(ans == realans);
	}
#endif
}