#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
 
/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

bool pr[10000007];
vector<int> q;
int n, m;
int a[100007];
int b[100007];
int ma[10000007], ma2[10000007], ma3[10000007];

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("just.in", "r", stdin);
        //freopen("just.out","w", stdout);
    }
	for (int i = 2; i <= 10007; i++) {
		if (!pr[i]) {
			q.pub(i);
			for (int j = 2 * i; j <= 10000005; j += i)
				pr[j] = 1;
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j < m; j++)
		scanf("%d", &b[j]);
	for (int i = 0; i < n; i++) {
		int cop = a[i];
		int d = 0;
		while (pr[cop] && q[d] * q[d] <= cop) {
			while (cop % q[d] == 0)
				cop /= q[d], ma[q[d]]++;
			d++;
		}
		if (cop != 1)
			ma[cop]++;
	}
	for (int i = 0; i < m; i++) {
		int cop = b[i];
		int d = 0;
		while (pr[cop] && q[d] * q[d] <= cop) {
			while (cop % q[d] == 0) {
				cop /= q[d];
				if (ma[q[d]] > 0)
					ma[q[d]]--, ma2[q[d]]++, ma3[q[d]]++;
			}
			d++;
		}
		if (cop != 1) {
			if (ma[cop] > 0)
				ma[cop]--, ma2[cop]++, ma3[cop]++;
		}
	}
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++) {
		int cop = a[i];
		int d = 0;
		while (pr[cop] && q[d] * q[d] <= cop) {
			while (cop % q[d] == 0) {
				cop /= q[d];
				if (ma2[q[d]] > 0)
					ma2[q[d]]--, a[i] /= q[d];
			}
			d++;
		}
		if (cop != 1) {
			if (ma2[cop] > 0)
				ma2[cop]--, a[i] /= cop;
		}
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < m; i++) {
		int cop = b[i];
		int d = 0;
		while (pr[cop] && q[d] * q[d] <= cop) {
			while (cop % q[d] == 0) {
				cop /= q[d];
				if (ma3[q[d]] > 0)
					ma3[q[d]]--, b[i] /= q[d];
			}
			d++;
		}
		if (cop != 1) {
			if (ma3[cop] > 0)
				ma3[cop]--, b[i] /= cop;
		}
		printf("%d ", b[i]);
	}
}