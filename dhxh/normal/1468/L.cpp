#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;
const int N = 100;

int n, m, t;

long long npow(__int128 b, long long x){
	__int128 ret = 1;
	while(x){
		if(x & 1){
			ret = ret * b;
			if(ret >= 2e18) ret = 2e18;
		}
		b = b * b;
		if(b >= 2e18) b = 2e18;
		x >>= 1;
	}
	return ret;
}

long long a[maxn];
unordered_map <long long, vector <long long> > mp;
vector <pair <long long, long long> > vec;
vector <int> prime;

long long check(int x, long long p){
	long long l = 1, r = pow(p, 1.0 / x) + 100;
	while(l < r){
		long long mid = (l + r) / 2;
		if(npow(mid, x) < p){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	if(npow(l, x) == p) return l;
	else return -1;
}

long long qpow(__int128 b, long long x, long long m){
	__int128 ret = 1;
	while(x){
		if(x & 1){
			ret = ret * b % m;
		}
		b = b * b % m;
		x >>= 1;
	}
	return ret;
}

bool miller_rabin(long long n){
	if(n < 2) return false;
	if(n == 2) return true;
	for(auto x : prime){
		if(x >= n) break;
		if(qpow(x, n - 1, n) != 1) return false;
	}
	return true;
}

bool cmp(vector <long long> &A, vector <long long> &B){
	return A.size() > B.size();
}

void solve(){
	for(auto T : vec){
		int c = 0;
		set <long long> s;
		for(auto U : mp){
			if(U.second.size() < 2) continue;
			while(T.first % U.first == 0){
				T.first /= U.first;
				s.insert(U.first);
			}
		}
		if(T.first == 1 and s.size() * 2 + 1 <= m){
			printf("%lld ", T.second);
			for(auto x : s){
				for(auto y : mp[x]){
					printf("%lld ", y);
				}
			}
			
			m -= s.size() * 2 + 1;
			
			for(auto U : mp){
				if(U.second.size() < 2) continue;
				if(s.count(U.first)) continue;
				if(m == 0) break;
				for(auto x : U.second){
					printf("%lld ", x);
				}
				m -= 2;
			}
			printf("\n");
			exit(0);
		}
	}
}

int main(){
	int i, j;
	
	for(i=2;i<=N;i++){
		bool flag = false;
		for(j=2;j<i;j++){
			if(i % j == 0){
				flag = true;
				break;
			}
		}
		if(!flag) prime.push_back(i);
	}
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		long long z = a[i];
		for(j=60;j>=2;j--){
			long long tmp = check(j, a[i]);
			if(tmp != -1){
				z = tmp;
				break;
			}
		}
		if(miller_rabin(z)){
			if(!mp.count(z)) mp[z] = {};
			mp[z].push_back(a[i]);
		}else{
			vec.push_back({z, a[i]});
		}
	}
	
	if(m == 1){
		printf("0\n");
		return 0;
	}
	
	vector <vector <long long> > A;
	vector <pair <long long, long long> > ans;
	
	for(auto x : mp){
		if(x.second.size() >= 2){
			A.push_back(x.second);
			for(auto y : x.second){
				ans.push_back({x.first, y});
			}
		}
	}
	
	if(ans.size() >= m){
		sort(A.begin(), A.end(), cmp);
		vector <long long> ans;
		int c = m;
		for(i=0;i<A.size();i++){
			if(A[i].size() <= c){
				c -= A[i].size();
			}else{
				if(c == 1){
					if(i > 0 and A[0].size() > 2){
						A[0].pop_back();
						A[i].resize(2);
						c = 0;
					}else{
						solve();
						printf("0\n");
						return 0;
					}
				}else{
					A[i].resize(c);
					c = 0;
				}
			}
		}
		for(i=0;i<A.size();i++){
			for(auto x : A[i]){
				printf("%lld ", x);
			}
		}
		printf("\n");
		return 0;
	}else{
		for(auto T : vec){
			for(auto U : ans){
				if(U.first == 1) continue;
				while(T.first % U.first == 0){
					T.first /= U.first;
				}
			}
			if(T.first == 1){
				ans.push_back(T);
			}
		}
		
		if(ans.size() >= m){
			ans.resize(m);
			for(auto [y, x] : ans){
				printf("%lld ", x);
			}
			printf("\n");
			return 0;
		}
	}
	
	printf("0\n");
	
	return 0;
}