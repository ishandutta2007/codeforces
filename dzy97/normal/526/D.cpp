#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000010

int fail[N], n, m;
char str[N];
bool ok[N];

int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);
	fail[1] = 0;
	int j = 0;
	for(int i = 2;i <= n;i ++){
		while(j && str[j + 1] != str[i]) j = fail[j];
		if(str[j + 1] == str[i]) j ++;
		fail[i] = j;
	}
//	for(int i = 1;i <= n;i ++) cout << fail[i] << " ";cout << endl;
	for(int i = 1;i <= n;i ++){
		int cur = i / (i - fail[i]);
                int pre = (i - 1) / (i - fail[i]) + 1;
		if(1 + (pre - 1) / (m + 1) <= cur / m) ok[i] = 1; else ok[i] = 0;
	}
	for(int i = 1;i <= n;i ++) putchar(48 + ok[i]);
	return 0;
}