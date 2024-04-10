#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

vector <int> vec;

int n, m, t;
int cnt = 60;

map <int, bool> s;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int gcd(int x, int y){
	if(y){
		return gcd(y, x % y);
	}else{
		return x;
	}
}

int query(int x){
	cout << "? " << x << endl;
	cin >> x;
	return x;
}

int main(){
	int i, j;
	int l = 1, r = 1e9;
	int mid;
	int x;
	int d;
	
	srand(time(0));
	
	cin >> n;
	
	if(n < 60){
		for(i=1;i<=n;i++){
			vec.push_back(query(i));
		}
		sort(vec.begin(), vec.end());
		cout << "! " << vec[0] << " " << vec[1] - vec[0] << endl;
		return 0;
	}
	
	while(l < r){
		mid = (l + r) / 2;
		cnt--;
		cout << "> " << mid << endl;
		cin >> x;
		if(x){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	for(i=1;i<=cnt;i++){
		x = 1ll * rand() * rand() % n + 1;
		while(s[x]){
			x = 1ll * rand() * rand() % n + 1;
		}
		s[x] = true;
		vec.push_back(query(x));
	}
	
	sort(vec.begin(), vec.end());
	
	d = vec[1] - vec[0];
	
	for(i=2;i<vec.size();i++){
		d = gcd(d, vec[i] - vec[i - 1]);
	}
	
	cout << "! " << l - (n - 1) * d << " " << d << endl;
	
	return 0;
}