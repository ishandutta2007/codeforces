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
	for(int i = 1; i <= n; ++i) {
		scanf("%d",a+i);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 2; j <= n; ++j) {
			if(a[j] < a[j-1]) {
				swap(a[j],a[j-1]);
				printf("%d %d\n",j-1,j);
			}
		}
	}
}