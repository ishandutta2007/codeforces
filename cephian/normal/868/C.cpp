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

int n,k;
int type[16]={};

int bc(int x) {
	int a = 0;
	while(x) {
		++a;
		x^=x&-1;
	}
	return a;
}

int main() {	
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; ++i) {
		int m = 0;
		for(int j = 0; j < k; ++j) {
			int a;
			scanf("%d",&a);
			if(a) m ^= (1<<j);
		}
		++type[m];
	}
	bool ok = type[0] > 0;
	int B = 1<<k;

	for(int i = 0; i < B; ++i) {
		for(int j = i+1; j < B; ++j) {
			// cout << i << " " << j << endl;
			if((i&j) == 0 && type[i]>0 && type[j]>0)
				ok = true;
		}
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
}