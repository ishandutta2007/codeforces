#include <bits/stdc++.h>

#define REPLACE 2
#define NONE 0
#define INSERT 1
#define DELETE -1

using namespace std;
typedef long long int ll;

int dp[1001][1001];
int mov[1001][1001];
string s,t;

void generateDP() {
	for(int i=0;i<=s.length();++i) {
		dp[0][i] = i; // i.e. deleting
		mov[0][i] = DELETE;
	}
	
	// t = goal
	int v;
	for(int it = 1;it<=t.length();++it) {
		for(int is = 0;is<=s.length();++is) {
			// start with insert, can always do that;
			dp[it][is] = dp[it-1][is] + 1;
			mov[it][is] = INSERT;
			if(is > 0) {
				// try replacing or skipping
				if(t.at(it-1) == s.at(is-1)) {
					if((v = dp[it-1][is-1]) < dp[it][is]) {
						dp[it][is] = v;
						mov[it][is] = NONE;
					}
				} else if((v = dp[it-1][is-1]+1) < dp[it][is]) {
					dp[it][is] = v;
					mov[it][is] = REPLACE;
				}
				
				// try deleting
				if((v = dp[it][is-1]+1) < dp[it][is]) {
					dp[it][is] = v;
					mov[it][is] = DELETE;
				}
			}
		}
	}
	
	
}

class pmove{
	public:
	int it, is, next;

	pmove(int a, int b, int c) :it(a), is(b), next(c) {}

};


int main() {
	cin >> s >> t;
	generateDP();
	cout << dp[t.length()][s.length()] << endl;
	
	stack<pmove> St;
	stack<string> Sst;

	int it=t.length(), is=s.length();
	while(it > 0 || is > 0) {
		switch(mov[it][is]) {
			case DELETE: --is; St.push(pmove(it, is, DELETE)); Sst.push(string("DELETE ") + to_string(it+1)); break;
			case REPLACE: --is; --it; St.push(pmove(it, is, REPLACE)); Sst.push(string("REPLACE ") + to_string(it+1) + ' ' + t.at(it)); break;
			case INSERT: --it; St.push(pmove(it, is, INSERT)); Sst.push(string("INSERT ") + to_string(it+1) + ' ' + t.at(it)); break;
			default: /*none*/ --it; --is; St.push(pmove(it, is, NONE)); break;
		}
	}

	while(Sst.size() > 0) {
		cout << Sst.top() << endl;
		Sst.pop();
	}


	return 0;
}