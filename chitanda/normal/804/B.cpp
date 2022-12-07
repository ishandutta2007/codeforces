#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

char s[1000100];
int pre[1000100];

int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		pre[i] = (pre[i - 1] * 2 + 1) % M;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(s[i] == 'a'){
			cnt++;
		}else{
			ans = (ans + pre[cnt]) % M;
		}
	}
	printf("%d\n", ans);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}