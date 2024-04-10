#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int a[4], b[4];

int main(){
	for (int i = 0; i < 3; i++)	scanf("%d", &a[i]);
	for (int i = 0; i < 3; i++)	scanf("%d", &b[i]);
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		if (a[i]^b[i])	cnt++;
	if (cnt == 3)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}