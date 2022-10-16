#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1005;

int t, n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v;
		while(n--){
			int a; cin>>a;
			if(a == 1){
				v.push_back(1);
			}
			else{
				while(a != v.back()+1){
					v.pop_back();
				}
				v.back()++;
			}
			for(int i = 0; i < size(v); i++)
				cout<<v[i]<<".\n"[i+1 == size(v)];
		}
	}
}
// It is guaranteed that in each test case at least one fitting list exists.