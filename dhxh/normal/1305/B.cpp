#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t;

string str;

int a[100005];
int b[100005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> str;
	n = str.length();
	str = "0" + str;
	
	for(i=1;i<=n;i++){
		a[i] = a[i - 1];
		if(str[i] == '(') a[i]++;
	}
	
	for(i=n;i>0;i--){
		b[i] = b[i + 1];
		if(str[i] == ')') b[i]++;
	}
	
	int cnt = 0;
	
	for(i=1;i<=n;i++){
		if(str[i] == '(' and a[i] <= b[i + 1]){
			cnt++;
		}
	}
	
	if(!cnt){
		printf("0\n");
		return 0;
	}
	
	printf("%d\n%d\n", 1, cnt * 2);
	
	int x = 0;
	for(i=1;i<=n;i++){
		if(str[i] == '('){
			x++;
			printf("%d ", i);
			if(x == cnt) break;
		}
	}
	
	vector <int> vec;
	
	x = 0;
	for(i=n;i>0;i--){
		if(str[i] == ')'){
			x++;
			vec.push_back(i);
			if(x == cnt) break;
		}
	}
	
	reverse(vec.begin(), vec.end());
	
	for(auto i : vec){
		printf("%d ", i);
	}
	printf("\n");
	
	return 0;
}