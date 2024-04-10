#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 20;

int n, k, p;
vector<int>	vec, sec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> p;
	p = k - p;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;
		if (temp%2 == 1)
			vec.push_back(temp);
		else
			sec.push_back(temp);
	}
	if ((int)vec.size() < p || (int)vec.size() % 2 != p % 2){
		cout << "NO" << endl;
		return	0;
	}
	if (p + ((int)vec.size() - p)/2 + (int)sec.size() < k){
		cout << "NO\n";
		return	0;
	}

	if (p == 0){
		cout << "YES\n";
		while (k > 1 && sec.size()){
			cout << "1 " << sec.back() << "\n";
			sec.pop_back();
			k--;
		}
		while (k > 1 && vec.size()){
			cout << 2 << " " << vec.back() << " ";
			vec.pop_back();
			cout << vec.back() << endl;
			vec.pop_back();
			k--;
		}
		cout << vec.size() + sec.size() << " ";
		for (int v:sec)
			cout << v << " ";
		for (int u:vec)
			cout << u << " ";
		cout << endl;
		return	0;
	}


	k -= p;
	cout << "YES\n";
	for (int i = 0; i < p - 1; i++){
		cout << 1 << " " << vec.back() << "\n";
		vec.pop_back();
	}
	for (; k && (int)sec.size();){
		cout << 1 << " " << sec.back() << "\n";
		sec.pop_back();
		k--;
	}
	while (k--){
		cout << 2 << " " << vec.back() << " ";
		vec.pop_back();
		cout << vec.back() << "\n";
		vec.pop_back();
	}
	
	cout << (int)vec.size() + (int)sec.size() << " ";
	for (int v:vec)
		cout << v << " ";
	for (int u:sec)
		cout << u << " ";
	cout << endl;
	return	0;
}