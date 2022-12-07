#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;

char s[1111];
int res[1111];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	bool tag = 0;
	for(int i = n - 1; i >= 0; --i){
		if(tag == 0){
			if(s[i] == 'a') res[i] = 1, tag ^= 1;
		}else{
			if(s[i] == 'b') res[i] = 1, tag ^= 1;
		}
	}
	for(int i = 0; i < n; ++i) printf("%d ", res[i]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}