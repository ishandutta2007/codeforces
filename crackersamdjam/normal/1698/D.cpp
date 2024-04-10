#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

// #define STRESS
#if defined(STRESS) && defined(LOCAL)
#define TEST
#endif

using namespace std;
using ll = long long;
int const MM = 1e4+5;

//mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 g((uint64_t) new char);
mt19937_64 g(0);
int randint(int l, int r){return uniform_int_distribution<int>(l, r)(g);}
long long randl(long long l, long long r){return uniform_int_distribution<long long>(l, r)(g);}
double randf(double l, double r){return uniform_real_distribution<double>(l, r)(g);}

int t, n, cnt;

#ifdef TEST
vector<int> vv;
#endif

vector<int> ask(int l, int r){
	assert(++cnt <= 15);
#ifdef TEST
	vector<int> ret;
	for(int i = l; i <= r; i++){
		ret.emplace_back(vv[i-1]);
		sort(all(ret));
	}
	return ret;
#endif
	cout<<"? "<<l<<' '<<r<<endl;
	vector<int> v(r-l+1);
	for(int &i: v)
		cin>>i;
	return v;
}

int main(int argc, char *args[]){
	int seed = argc > 1 ? atoi(args[1]) : 0;
	// seed = 2;
	g = mt19937_64(seed);

#ifdef TEST
	pr("seed", seed);
	t = 1;
#else
	cin>>t;
#endif

	while(t--){
		cnt = 0;

#ifdef TEST
		n = randint(3, 10);
		if(n%2 == 0) n++;
		vv.resize(n);
		iota(all(vv), 1);

		int fix = randint(1, n);
		vector<int> ps;
		for(int i = 1; i <= n; i++){
			if(i != fix)
				ps.emplace_back(i);
		}
		shuffle(all(ps), g);
		for(int i = 0; i < size(ps); i += 2){
			swap(vv[ps[i]-1], vv[ps[i+1]-1]);
		}
		// n = 5;
		// vv = {4,2,5,1,3};
		for(int i: vv)
			cerr<<i<<' ';
		cerr<<endl;
#else
		cin>>n;
#endif

		vector<int> bad(n+1);
		vector<int> good(n);
		iota(all(good), 1);

		while(size(good) > 1){
			int sz = (int)size(good);
			int m = good[sz/2];
			int l = good[0], r = good.back();
			assert(sz%2 == 1);
			pr("go", l, r, m);
			// for(auto i: good)
			// 	cerr<<i<<' ';
			// cerr<<"\n\n";

			auto v = ask(l, m);
			vector<int> val(n+1);
			for(int i = l; i <= m; i++){
				val[i] = 1;
			}
			for(int i: v){
				val[i] ^= 1;
				pr("mark", i);
			}
			vector<int> ls, rs;
			for(int i = l; i <= m; i++){
				if(bad[i]) continue;
				if(val[i] == 0){
					ls.emplace_back(i);
				}
				else{
					bad[i] = 1;
				}
			}
			for(int i = m+1; i <= r; i++){
				if(bad[i]) continue;
				if(val[i] == 0){
					rs.emplace_back(i);
				}
				else{
					bad[i] = 1;
				}
			}
			if(size(ls)%2){
				good = ls;
			}
			else{
				assert(size(rs)%2);
				good = rs;
			}
		}
		cout<<"! "<<good[0]<<endl;

#ifdef TEST
		assert(vv[good[0]-1] == good[0]);
#endif
	}
}