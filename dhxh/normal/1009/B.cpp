#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

string str;

int cnt = 0;

int a[maxn];
int b[maxn];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	int i, j;
	char ch;
	int s, t;
	
	cin >> str;
	
	n = str.length();
	
	for(i=0;i<n;i++){
		b[i + 1] = str[i] - '0';
		if(b[i + 1] == 1){
			cnt++;
		}
	}
	
	for(i=1;i<=cnt;i++){
		a[i] = 1;
	}
	
	for(i=1;i<=n;i++){
		if(b[i] != 1){
			cnt++;
			a[cnt] = b[i];
		}
	}
	
	for(i=1;i<=n;i++){
		if(a[i] == 2){
			i++;
			break;
		}
	}
	
	sort(a + 1, a + i);
	
	for(i=1;i<=n;i++){
		cout << a[i];
	}
	
	cout << endl;
	
	return 0;
}