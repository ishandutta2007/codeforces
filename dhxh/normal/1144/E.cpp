#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

string a;
string b;

int ans[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	cin >> a >> b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	for(i=0;i<n;i++){
		ans[i] += a[i] + b[i] - 'a' * 2;
		ans[i + 1] = ans[i] / 26;
		ans[i] = ans[i] % 26;
	}
	
	for(i=n;i>=0;i--){
		if(ans[i] % 2){
			ans[i - 1] += 26;
		}
		ans[i] /= 2;
	}
	
	for(i=n-1;i>=0;i--){
		cout << (char)(ans[i] + 'a');
	}
	cout << endl;
	
	return 0;
}