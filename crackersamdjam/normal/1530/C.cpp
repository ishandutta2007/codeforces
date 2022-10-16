#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 1e5+5;

int t, n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		priority_queue<int> sta, stb;
		priority_queue<int, vector<int>, greater<>> ina;
		for(int i = 0, a; i < n; i++){
			cin>>a;
			sta.emplace(a);
		}
		for(int i = 0, a; i < n; i++){
			cin>>a;
			stb.emplace(a);
		}

		int va = 0, vb = 0;
		int k = n-n/4;
		for(int i = 0; i < k; i++){
			va += sta.top();
			ina.emplace(sta.top());
			sta.pop();
			vb += stb.top();
			stb.pop();
		}
		int old = n;
		while(va < vb){
			n++;
			sta.emplace(100);
			stb.emplace(0);

			while(size(sta) and size(ina) and ina.top() < sta.top()){
				va += sta.top()-ina.top();
				ina.emplace(sta.top());
				sta.emplace(ina.top());
				ina.pop();
				sta.pop();
			}

			int kk = n-n/4;
			while(k < kk){
				k++;
				va += sta.top();
				ina.emplace(sta.top());
				sta.pop();
				vb += stb.top();
				stb.pop();
			}
			// pr(n-old, va, vb);
		}
		cout<<n-old<<'\n';
		// pr(n-old);
	}
}