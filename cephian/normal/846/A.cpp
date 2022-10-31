#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int a[105];

int main() {	
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",a+i);
	}
	int res = 0;
	for(int i = 0; i <= n; ++i) {
		int b = 0;
		for(int j = 0; j < i; ++j)
			b += a[j] == 0;
		for(int j = i; j < n; ++j)
			b += a[j] == 1;
		res = max(res,b);
	}
	printf("%d\n",res);
}