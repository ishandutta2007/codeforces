#include <cstdio>
#include <cinttypes>
#include <map>
#include <cstring>
#define fori(i,s,e) for (int i = s; i < ((int)e); i++)
using namespace std;

char s[4008];
long long a;
int n;

int main() {
	scanf("%" SCNd64 " ", &a);
	fgets(s, 4004, stdin);
	n = strlen(s);
	while (s[n-1] < '0' || s[n-1] > '9') n--;
	map<long long,long long> m;
	long long sols = 0;
	if (a == 0) {
		long long zs = 0;
		fori (i, 0, n) {
			int j = i;
			while (s[j] == '0') j++;
			zs += j - i;
		}
		sols = zs * (n * (n+1) - zs);
	} else {
		fori (i, 0, n) {
			long long ttl = 0;
			fori (j, i, n) {
				ttl += (s[j] - '0');
				if (ttl > 0 && a % ttl == 0) {
					long long dr = a / ttl;
					if (m.count(dr)) sols += 2*m[dr];
					m[ttl] = (m.count(ttl) ? m[ttl] : 0) + 1;
					if (ttl * ttl == a) sols++;
				}
			}
		}
	}
	printf("%" PRId64 "\n", sols);
}