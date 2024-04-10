#include <bits/stdc++.h>
using namespace std;

int n, cnt[200];
char str[100010];
#define mo 1000000007

int pow(int a, int b, int c){
	int ret = 1;
	while(b){
		if(b & 1) ret = 1LL * ret * a % c;
		b >>= 1;
		a = 1LL * a * a % c;
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	scanf("%s", str + 1);
	sort(str + 1, str + n + 1);
	for(int i = 1;i <= n;i ++) cnt[str[i]] ++;
	int mx = 0, cc = 0;
	if(cnt['A'] > mx) mx = cnt['A'], cc = 1; else if(cnt['A'] == mx) cc ++;
	if(cnt['G'] > mx) mx = cnt['G'], cc = 1; else if(cnt['G'] == mx) cc ++;
	if(cnt['T'] > mx) mx = cnt['T'], cc = 1; else if(cnt['T'] == mx) cc ++;
	if(cnt['C'] > mx) mx = cnt['C'], cc = 1; else if(cnt['C'] == mx) cc ++;
	printf("%d\n", pow(cc, n, mo));
	return 0;
}