#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int n, t;
array<int, 5> a[50005];

void run(){
	int id = 0;
	for(int i = 1; i < n; i++){
		int k = 0;
		for(int j = 0; j < 5; j++)
			k += a[i][j] < a[id][j];
		if(k >= 3)
			id = i;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		int k = 0;
		for(int j = 0; j < 5; j++)
			k += a[id][j] < a[i][j];
		if(k >= 3)
			cnt++;
	}
	if(cnt == n-1){
		cout<<id+1<<'\n';
	}
	else{
		cout<<"-1\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 5; j++)
				cin>>a[i][j];
		}
		run();
	}
}