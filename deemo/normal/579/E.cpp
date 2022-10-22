#include<cstdio>
#include<vector>
#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

int n;
vector<long double>	vec, sec;

long double gm(){
	long double sum = 0, ret = 0;
	for (int i = 0; i < n;i++){
		if (sum < 0)
			sum = 0;
		sum += sec[i];
		ret = max(ret, sum);
	}
	return ret;
}

long double get(long double x){
	copy(vec.begin(), vec.end(), sec.begin());
	for (int i = 0; i < n; i++)
		sec[i] -= x;
	long double ret = gm();
	for (int i = 0; i < n; i++)
		sec[i] *= -1;
	return max(ret, gm());
}

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vec.resize(n);
	sec.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	long double b = -2e4, e = 2e4, m1, m2;

	for (int i = 0; i < 200; i++){
		m1 = (b * 5 + e * 4) / 9;
		m2 = (b * 4 + e * 5) / 9;

		long double first = get(m1), second = get(m2);	

		if (first < second)	e = m2;
		else	b = m1;	
	}
	cout << fixed << setprecision(7);
	cout << get(b) << endl;
	return 0;
}