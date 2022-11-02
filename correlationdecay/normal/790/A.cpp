#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>
#define maxn 109
using namespace std;
string s[maxn];
int a[maxn];
string name[maxn * maxn];
int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n - k + 1; i++)
		cin >> s[i];
	for(int i = 1;i < k; i++){
		a[i] = i;
	}
	int cur = k;
	for(int i = k; i <= n; i++){
		if(s[i - k + 1] == "YES"){
			a[i] = cur++;
		}
		else{
			a[i] = a[i - k + 1];
		}
	}
	int tot = 0;
	for(char c = 'A'; c <= 'Z'; c++){
		for(char d ='a'; d <= 'z'; d++){
			tot++;
			name[tot].push_back(c);
			name[tot].push_back(d);
		}
	}
	for(int i = 1; i <= n; i++)
		cout << name[a[i]] << " ";
	return 0;
}