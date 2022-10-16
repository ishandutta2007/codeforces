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

int n, tc;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>tc;
	while(tc--){
		cin>>n>>s;
		int dif = 0;
		for(auto c: s)
			dif += c == '0';

		int ok = dif%2 == 0;
		int k = (n-dif)/2;
		string a, b;

		for(auto c: s){
			if(c == '0'){
				a += '(';
				b += ')';
				swap(a, b);
			}
			else{
				if(k){
					k--;
					a += '(';
					b += '(';
				}
				else{
					a += ')';
					b += ')';
				}
			}
		}

		int ac = 0, bc = 0;
		for(int i = 0; i < n; i++){
			ac += (a[i] == '(') ? 1 : -1;
			bc += (b[i] == '(') ? 1 : -1;
			if(ac < 0 or bc < 0){
				ok = 0;
			}
		}

		if(!ok)
			cout<<"NO\n";
		else
			cout<<"YES\n"<<a<<'\n'<<b<<'\n';
	}
}