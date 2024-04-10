#include<bits/stdc++.h>

using namespace std;

int a, b;
vector<int>	vec;

int main(){
	cin >> a >> b;
	vec.push_back(b);
	while (b > a){
		if (b % 10 == 1)
			b /= 10, vec.push_back(b);
		else{
			if (b & 1){
				cout << "NO\n";
				return 0;
			}
			b >>= 1, vec.push_back(b);
		}
	}
	if (b < a){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << (int)vec.size() << "\n";
	reverse(vec.begin(), vec.end());
	for (auto x:vec)
		cout << x << " ";
	cout << "\n";
	return 0;
}