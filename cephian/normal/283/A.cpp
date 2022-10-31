#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 2e5+5;
ll A[N],O[N]={},sz=1,sm=0,offs=0;

int main() {
	// ios::sync_with_stdio(0); cin.tie(0);
	int n,t;
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&t);
		if(t == 1) {
			int a,x;
			scanf("%d%d",&a,&x);
			O[a] += x;
			sm += a*x;
		} else if(t == 2) {
			int k;
			scanf("%d",&k);
			A[++sz] = k-offs;
			sm += k;
		} else if(t == 3) {
			offs += O[sz];
			O[sz] = 0;
			sm -= A[sz--]+offs;
		}
		printf("%.8lf\n",double(sm)/sz);
	}
}