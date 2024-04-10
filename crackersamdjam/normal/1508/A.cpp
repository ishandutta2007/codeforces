#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;

int t, n;

string go(string a, string b, char c){
	string s;
	vector<int> va = {-1}, vb = {-1};
	for(int i = 0; i < 2*n; i++){
		if(a[i] == c)
			va.push_back(i);
		if(b[i] == c)
			vb.push_back(i);
	}
	va.push_back(2*n);
	vb.push_back(2*n);
	for(int i = 1; i < max(size(va), size(vb)); i++){
		int cnta = (i < size(va)) ? (va[i]-1 - va[i-1]) : 0;
		int cntb = (i < size(vb)) ? (vb[i]-1 - vb[i-1]) : 0;
		for(int z = 0; z < max(cnta, cntb); z++)
			s += c^1;
		if(i < max(size(va), size(vb))-1)
			s += c;
	}
	// pr(a, b, c, s);
	while(size(s) < 3*n)
		s += '0';
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		string s[3];
		cin>>n>>s[0]>>s[1]>>s[2];
		for(char c = '0'; c <= '1'; c++){
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < i; j++){
					auto ans = go(s[i], s[j], c);
					if(size(ans) == 3*n){
						cout<<ans<<'\n';
						goto out;
					}
				}
			}
		}
		out:;
	}
}