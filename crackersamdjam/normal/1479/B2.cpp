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
const int MM = 1e5+5;

int n, a[MM], ans;
vector<int> v[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		v[a[i]].emplace_back(i);
	}
	for(int i = 0; i <= n; i++)
		v[i].emplace_back(n+1);

	int la = 0, lb = 0;

	for(int i = 1; i <= n; i++){
		// pr(i, la, lb);
		if(a[i] == la or a[i] == lb){
		}
		else{
			ans++;
			int na = *upper_bound(all(v[la]), i);
			int nb = *upper_bound(all(v[lb]), i);
			if(na < nb){
				lb = a[i];
			}
			else{
				la = a[i];
			}
		}
	}

	cout<<ans<<'\n';
}
/*
a.....a.bbb
sat. a first because closer

*/