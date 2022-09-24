#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define upmin(ans,ansx) (ans)=min((ans),(ansx))
#define upmax(ans,ansx) (ans)=max((ans),(ansx))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool flagsex = false;
int Ans, OpAns = -1;

void sex(const int& N) {
	printf(">");
	for(int i = 0; i < 48+N; i++) printf("+");
	printf(".");
}
int main() {
	for(;;) {
		if(!flagsex) {
			int c;
			if(1 != scanf("%d", &c)) break;
			if(-1 == OpAns) Ans = c;
			else {
				if(OpAns == '+') Ans += c;
				if(OpAns == '-') Ans -= c;
			}
			flagsex = true;
		} else {
			char c; scanf(" %c", &c);
			OpAns = c; flagsex = false;
		}
	}
	vector<int> V;
	if(Ans == 0) V.pb(0);
	else for(; Ans; V.pb(Ans%10), Ans /= 10);
	reverse(allv(V));
	for(const int& v : V) sex(v);
	puts("");
	return 0;
}