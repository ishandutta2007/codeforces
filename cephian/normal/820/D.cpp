#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 2e6+5;
int p[N];

ll init = 0;

set<pii> lt;
int geq_sz=0;

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",p+i);
		--p[i];
		p[i+n] = p[i];
		init += abs(i-p[i]);
		if(p[i] < i) lt.insert(pii(i-p[i],p[i]));
		else ++geq_sz;
	}
	ll score=init, best = 0;
	for(int i = 1; i < n; ++i) {
		int nxt = n+i-1;
		init -= p[i-1];
		--geq_sz;
		init = init + geq_sz - lt.size();
		//pop thing prev assigned to 1
		//move from lt to geq
		while(lt.size() && lt.begin()->fi-i == 0) {
			++geq_sz;
			lt.erase(lt.begin());
		}
		if(p[nxt] == n-1) {
			++geq_sz;
		} else {
			lt.insert(pii((n-1)-p[nxt]+i,p[nxt]));
			init += abs(n-1 - p[nxt]);
		}

		if(init < score) {
			score = init;
			best = i;
		}
	}
	printf("%I64d %I64d\n",score,(n-best)%n);
}