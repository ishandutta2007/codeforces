#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, k;
	cin >> n >> k;
	deque <int> vec;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		bool f = true;
		for(int i = 0; i < vec.size(); i++)
			if(vec[i] == x)
				f = false;
		if(f)
			vec.push_front(x);
		if(vec.size() > k)
			vec.pop_back();
	}
	n = vec.size();
	cout << n << endl;
	for (int i = 0; i < n;  i++)
		cout << vec[i] << ' ';
}