#include<iostream>
#include<vector>

using namespace std;

vector<int>	vec;

void cal(int l, int r){
	if (r < l)	return;
	if (l == r){
		vec.push_back(l);
		return;
	}
	vec.push_back(l + 1);
	vec.push_back(r);
	cal(l + 2, r - 2);
	vec.push_back(l);
	vec.push_back(r - 1);
}

int main(){
	int n;	cin >> n;
	if (n % 4 != 0 && n % 4 != 1)	cout << -1 << endl;
	else{
		cal(1, n);
		for (int u:vec)	cout << u << " ";
		cout << endl;
	}
	return 0;
}