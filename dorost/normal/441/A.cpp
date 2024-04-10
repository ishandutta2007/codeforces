#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, v;
	cin >> n >> v;
	vector <int> vec;
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		bool f = true;
		while(k--){
			int x;
			cin >> x;
			if(x < v && f)
				vec.push_back(i + 1), f = false;
		}
	}
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' '; 
}