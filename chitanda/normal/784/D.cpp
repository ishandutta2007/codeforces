#include<bits/stdc++.h>
using namespace std;

const int a[] = {8, -1, -1, 3, 6, 9, 4, 7, 0, 5};

int main(){
	string s;
	cin >> s;
	int n = s.size();
	bool flag = 1;
	for(int i = 0; i < n; ++i){
		if(a[s[i] - '0'] != s[n - i - 1] - '0') flag = 0;
	}
	printf("%s\n", flag ? "YES" : "NO");
	return 0;
}