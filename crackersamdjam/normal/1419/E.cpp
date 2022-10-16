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

int t;
ll n;
vector<ll> f;
vector<ll> v;
vector<int> cnt;

void go(int i, ll val){
	if(i == n){
		f.emplace_back(val);
		return;
	}
	for(int j = 0; j <= cnt[i]; j++){
		go(i+1, val);
		val *= v[i];
	}
}

int main(){
	scan(t);
	while(t--){
		scan(n);
		v.clear();
		f.clear();
		cnt.clear();
		for(ll i = 2; i*i <= n; i++){
			if(n%i == 0){
				v.emplace_back(i);
				cnt.emplace_back(0);
				while(n%i == 0){
					n /= i;
					cnt.back()++;
				}
			}
		}
		if(n > 1){
			v.emplace_back(n);
			cnt.emplace_back(1);
		}
		n = size(v);
		go(0, 1);

		sort(all(f));
		f.erase(unique(f.begin(), f.end()), f.end());
		// cerr<<"f ";
		// for(ll j: f)
		// 	cerr<<j<<' ';
		// cerr<<endl;
		// cerr<<"v ";
		// for(ll j: v)
		// 	cerr<<j<<' ';
		// cerr<<endl;
		// cerr<<"cnt ";
		// for(ll j: cnt)
		// 	cerr<<j<<' ';
		// cerr<<endl;

		set<ll> used;
		used.insert(1);
		vector<ll> pre(n);

		int ans = 0;
		used.insert(v[0]);
		for(int i = 1; i < n; i++){
			pre[i] = v[i]*v[i-1];
			used.insert(pre[i]);
			used.insert(v[i]);
		}
		if(n > 1){
			if(used.count(v[0]*v.back())){

				if(cnt[0] > 1){
					pre[0] = v[0]*v[0]*v.back();
					used.insert(pre[0]);
				}
				else if(cnt.back() > 1){
					pre[0] = v[0]*v.back()*v.back();
					used.insert(pre[0]);
				}
				else{
					ans = 1;
					pre[0] = 0;
				}
			}
			else{
				pre[0] = v[0]*v.back();
				used.insert(pre[0]);
			}
		}

		for(int i = 0; i < n; i++){
			if(pre[i])
				printf("%lld ", pre[i]);
			printf("%lld ", v[i]);
			for(ll j: f){
				if(j%v[i] == 0 and !used.count(j)){
					used.insert(j);
					printf("%lld ", j);
				}
			}
		}
		pc(10);
		print(ans);
	}
}