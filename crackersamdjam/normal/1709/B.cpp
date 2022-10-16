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
int const MM = 1e5+5;

int n, m, a[MM];
ll l[MM], r[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 2; i <= n; i++){
		r[i] = r[i-1]+max(0, a[i-1]-a[i]);
	}
	for(int i = n-1; i > 0; i--){
		l[i] = l[i+1]+max(0, a[i+1]-a[i]);
	}
	while(m--){
		int b, c;
		cin>>b>>c;
		if(b <= c){
			cout<<(r[c]-r[b])<<'\n';
		}
		else{
			cout<<(l[c]-l[b])<<'\n';
		}
	}
}