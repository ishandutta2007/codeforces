#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int a,b,c;
	scanf ("%d %d %d",&a,&b,&c);
	int cango = min({a/3,b/2,c/2});
	a -= 3*cango; b -= 2*cango; c -= 2*cango;
	int ret = 0;
	for (int st = 0; st < 7; st++) {
		int ree = 7 * cango;
		int na = a, nb = b, nc = c;
		for (int day = st;;day=(day+1)%7) {
			if (day == 0 || day == 1 || day == 4) --na;
			else if (day == 2 || day == 6) --nb;
			else --nc;
			if (na < 0 || nb < 0 || nc < 0) break;
			ree++;
		}
		ret = max(ret,ree);
	}
	printf ("%d\n",ret);
    return 0;
}