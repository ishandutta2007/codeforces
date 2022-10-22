#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int where[MN];
int main() {
	int q;
	scanf ("%d",&q); int curl = 0, curr = 0; bool first = 1;
	while (q--) {
		char c; int a;
		scanf (" %c %d",&c,&a);
		if (first) where[a] = first = 0;
		else {
			if (c == 'R') where[a] = ++curr;
			else if (c == 'L') where[a] = --curl;
			else {
				printf ("%d\n",min(where[a]-curl,curr-where[a]));
			}
		}
	}
    return 0;
}