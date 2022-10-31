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



int main() {	
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		ans = max(ans,a-25);
	}
	printf("%d\n",ans);
}