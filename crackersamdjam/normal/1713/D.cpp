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
int const MM = (1<<17)+5;

mt19937_64 g(132);
int randint(int l, int r){return uniform_int_distribution<int>(l, r)(g);}
long long randl(long long l, long long r){return uniform_int_distribution<long long>(l, r)(g);}
double randf(double l, double r){return uniform_real_distribution<double>(l, r)(g);}

int t, n, lim;

int ask(int a, int b){
	// if(--lim < 0){
	// 	pr("too many queries");
	// 	exit(0);
	// }
	cout<<"? "<<a<<' '<<b<<endl;
	int x; cin>>x;
	if(x == -1) abort();
	return x;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		n = 1<<n;
		lim = n*2;
		while(lim%3) lim++;
		lim /= 3;
		// pr("lim", lim, n);
		queue<int> q;
		for(int i = 1; i <= n; i++){
			q.push(i);
		}

		while(size(q) >= 4){
			vector<int> v;
			for(int tt = 0; tt < 4; tt++){
				v.push_back(q.front());
				q.pop();
			}
			if(g()%2) swap(v[0], v[1]);
			if(g()%2) swap(v[2], v[3]);

			int a = ask(v[0], v[2]);
			if(a == 1){
				if(ask(v[0], v[3]) == 1){
					q.push(v[0]);
				}
				else{
					q.push(v[3]);
				}
			}
			else if(a == 2){
				if(ask(v[2], v[1]) == 1){
					q.push(v[2]);
				}
				else{
					q.push(v[1]);
				}
			}
			else{
				if(ask(v[1], v[3]) == 1){
					q.push(v[1]);
				}
				else{
					q.push(v[3]);
				}
			}
		}
		if(size(q) == 2){
			vector<int> v;
			for(int tt = 0; tt < 2; tt++){
				v.push_back(q.front());
				q.pop();
			}
			if(ask(v[0], v[1]) == 1){
				q.push(v[0]);
			}
			else{
				q.push(v[1]);
			}
		}
		cout<<"! "<<q.front()<<endl;
	}
	pr("done");
}