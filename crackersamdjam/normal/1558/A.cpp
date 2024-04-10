#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t, a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		set<int> st;
		int f = (a+b+1)/2, s = a+b-f;
		for(int i = 0; i <= min(f, a); i++){
			int k = a-i;
			// A gets k breaks
			int nk = f-i;
			int nb = s-k;

			if(k <= s){
				st.insert(k+nk);
			}
		}

		f = (a+b)/2, s = a+b-f;
		for(int i = 0; i <= min(f, a); i++){
			int k = a-i;
			// A gets k breaks
			int nk = f-i;
			int nb = s-k;

			if(k <= s){
				st.insert(k+nk);
			}
		}

		cout<<size(st)<<'\n';
		for(int i: st)
			cout<<i<<' ';
		cout<<'\n';
	}
}