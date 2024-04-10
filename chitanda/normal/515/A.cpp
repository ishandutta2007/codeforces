#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int main(){
	int a, b, s;
	scanf("%d%d%d", &a, &b, &s);
	int tot = abs(a) + abs(b);
	if(tot > s || ((s - tot) & 1))
		puts("No");
	else
		puts("Yes");
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}