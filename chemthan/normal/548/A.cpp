#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
typedef long long ll;

char s[1001];
int k;

void solve(){
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>s>>k;
	if (strlen(s) % k != 0) {cout<<"NO"; return;}
	int len = strlen(s) / k;
	FOR(i, k){
		FOR(j, len) {if (s[i * len + j] != s[i * len + len - 1 - j]) {cout<<"NO"; return;}}
	}
	cout<<"YES";
}

int main(){
	solve();
	return 0;
}