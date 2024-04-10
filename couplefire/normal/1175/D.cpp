#include<bits/stdc++.h>

using namespace std;

const int N = 300009;

int n, k;
int a[N];

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	long long sum = 0;
	vector <long long> v;
	for(int i = n - 1; i >= 0; --i){
	    sum += a[i];
	    if(i > 0) v.push_back(sum);
	}
	
	long long res = sum;
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	
	for(int i = 0; i < k - 1; ++i)
	    res += v[i];
	    
	cout << res << endl;
	return 0;
}