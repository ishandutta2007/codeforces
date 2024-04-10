#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	array<vector<int>, 2> a;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[1LL * x * x % 3].push_back(i);
	}
	if((int)a[0].size() <= n / 2){
		string res(n, '1');
		for(auto i: a[0]){
			res[i] = '0';
		}
		for(auto t = 0; t < n / 2 - (int)a[0].size(); ++ t){
			res[a[1][t]] = '0';
		}
		cout << "0\n" << res << "\n";
	}
	else{
		string res(n, '1');
		for(auto i: a[1]){
			res[i] = '0';
		}
		for(auto t = 0; t < n / 2 - (int)a[1].size(); ++ t){
			res[a[0][t]] = '0';
		}
		cout << "2\n" << res << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////