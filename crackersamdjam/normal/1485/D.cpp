#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 505;

int n, m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int a; cin>>a;
			cout<<720720 - (i+j)%2*a*a*a*a<<' ';
		}
		cout<<'\n';
	}
}