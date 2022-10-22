#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(s) (int)s.size()
#define fast  ios_base::sync_with_stdio(false), cin.tie()

int main(){
	string a, b;
	cin >> a >> b;
	if(a == b){
		cout << -1;
	}else{
		cout << max(a.size(), b.size());
	}
}