#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int k;
int f[10010];

int main(){
	scanf("%d", &k);
	f[1] = 0;
	for(int i = 2; i <= 1000; ++i)
		f[i] = f[i - 1] + i - 1;
	if(k == 0){
		putchar('a');
		return 0;
	}
	char now = 'a';
	for(int i = 1000; i >= 2; --i){
		while(k >= f[i]){
			k -= f[i];
			for(int j = 0; j < i; ++j)
				putchar(now);
			++now;
		}
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}