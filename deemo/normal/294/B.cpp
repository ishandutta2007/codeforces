#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

vector<int>	a, b;

bool ok(int x){
	bool ret = 0;
	for (int i = 0; i <= a.size() && i <= x; i++){
		if (2 * b.size() + i < x)	continue;
		if ((x - i) % 2 != 0)	continue;
		
		int tsum = 0;
		for (int j = i; j < a.size(); j++)	tsum += a[j];
		for (int j = (x - i)/ 2; j < b.size(); j++)	tsum += b[j];
		ret |= bool(tsum <= x);
	}	
	return	ret;
}

int main(){
	int n;	cin >> n;
	int sum = 0;
	vector<pair<int, int>>	vec(n);
	for (int i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
		if (vec[i].first == 1)	a.push_back(vec[i].second);
		else	b.push_back(vec[i].second);
		sum += vec[i].first;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	
	for (int i = 1; i <= sum; i++)
		if (ok(i)){
			cout << i << endl;
			return 0;
		}

	return 0;
}