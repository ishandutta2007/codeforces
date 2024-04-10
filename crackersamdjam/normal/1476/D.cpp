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
const int MM = 3e5+5;

int t, n;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s;
		vector<int> pre(n+2), suf(n+2);
		for(int i = 1; i <= n; i++){
			if(s[i-1] == 'L'){
				if(i >= 2 and s[i-2] == 'R'){
					pre[i] = pre[i-2]+2;
				}
				else
					pre[i] = 1;
			}
		}
		for(int i = n-1; i >= 0; i--){
			if(s[i] == 'R'){
				if(i+1 < n and s[i+1] == 'L'){
					suf[i] = suf[i+2]+2;
				}
				else
					suf[i] = 1;
			}
		}
		for(int i = 0; i <= n; i++){
			int s = pre[i]+suf[i]+1;
			// cerr<<pre[i]<<' ';
			cout<<s<<' ';
		}
		cout<<'\n';
		// cerr<<endl;
		// for(int i = 0; i <= n; i++)
			// cerr<<suf[i]<<' ';
	}
}