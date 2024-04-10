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
const int MM = 2e5+5;

int n, k;
int vis[30][30];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	string s;
	int i = 0;
	while(size(s) < n){
		s.push_back('a'+i);
		int best = 1e9;

		for(int j = 0; j < k; j++){
			int b = (i+j)%k;
			best = min(best, vis[i][b]);
		}

		int to = 0;
		for(int j = 0; j < k; j++){
			int b = (i+j)%k;
			if(vis[i][b] == best){
				to = b;
				break;
			}
		}

		vis[i][to]++;
		i = to;
	}
	cout<<s<<'\n';
}