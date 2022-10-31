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

string str;

long long a[maxn];
long long b[maxn];

int c[maxn];

long long ans = 0;

bool cmp(int x, int y){
	if(!b[x] and !b[y]){
		return x > y;
	}
	if(!b[x]){
		return true;
	}
	if(!b[y]){
		return false;
	}
	return a[x] * b[y] > b[x] * a[y];
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long x = 0;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> str;
		for(j=0;j<str.length();j++){
			if(str[j] == 's'){
				a[i]++;
			}else{
				b[i]++;
				ans += a[i];
			}
		}
	}
	
	for(i=1;i<=2e5;i++)c[i] = i;
	
	sort(c + 1, c + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		ans += x * b[c[i]];
		x += a[c[i]];
	}
	
	cout << ans << endl;
	
	return 0;
}