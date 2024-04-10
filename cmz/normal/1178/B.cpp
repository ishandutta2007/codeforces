#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long n, aaa[N], bbb[N];
string s;
int kkkkk;
int main() {
	cin >> s;
	n=s.size()-1;
	for (long long i = 0; i <= n; i++) 
	if (s[i]=='v'&&s[i-1]=='v') aaa[i]=aaa[i-1]+1; else aaa[i]=aaa[i-1];
	
	
	for (long long i = n - 1; i >= 0; i--) 
	if (s[i]=='v'&&s[i+1]=='v') bbb[i]=bbb[i+1]+1; else bbb[i]=bbb[i+1];
	
	
	long long ans = 0;
	for (long long i = 0; i <= n; i++) if (s[i]== 'o') ans += 1LL * aaa[i - 1] * bbb[i + 1];
	
	printf("%I64d\n", ans);
	return 0;
}