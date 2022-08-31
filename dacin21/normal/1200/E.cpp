// Testing hash failure probabilty
#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC target ("avx,tune=native")
//Use above if bruteforcing with lots of small operations. Or just use it anytime, there's no downside. AVX is better slightly
/*
by farmersrice
*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 200013
#define INF 1000000000000000000LL
#define MOD 1000000007LL
#define IINF 1000000000
#define mp make_pair
#define pb push_back
#define remove pop
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
struct StringHashQuick {
	int mod1;
	int totalLength;
	int curLength;
	int base;
	int *prefix1; //Non-inclusive
	int *basePow1; //base to the power of i mod mod1.
 
	StringHashQuick(string s, int b, int c, int length) {
		totalLength = length; base = b; mod1 = c;
		curLength = s.size();
 
		prefix1 = new int[length + 1];
		basePow1 = new int[length + 1];
 
		prefix1[0] = 0;
		basePow1[0] = 1;
 
		for (int i = 1; i < length + 1; i++) {
			basePow1[i] = (1LL * basePow1[i - 1] * base) % mod1;
		}
 
		int hash1 = 0;
		for (int i = 0; i < s.size(); i++) {
			hash1 = (1LL * hash1 * base + s[i]) % mod1;
			prefix1[i + 1] = hash1;
		}
	}
 
	void concat(string s) {
		//cout << "we doing the concat "<< s << endl;
		int hash1 = prefix1[curLength];
		for (int i = 0; i < s.size() + 1; i++) {
			hash1 = (1LL * hash1 * base + s[i]) % mod1;
			prefix1[i + 1 + curLength] = hash1;
		}
		curLength += s.size();
	}
 
	//Inclusive
	int getHash(int start, int end) {
		int hash1 = (mod1 + prefix1[end + 1] - ((1LL * prefix1[start] * basePow1[end - start + 1]) % mod1)) % mod1;
 
		return hash1;
	}
 
	int getHash() {
		return prefix1[totalLength];
	}
};
 
int n;
string values[MAXN];
int position[MAXN];
string bigString;
 
int main() {
	if (fopen("FILENAME.in", "r")) {
		freopen("FILENAME.in", "r", stdin);
		freopen("FILENAME.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
 
	cin >> n;
 
	bigString = "";
	for (int i = 0; i < n; i++) {
		cin >> values[i];
		position[i] = bigString.size();
		bigString += values[i];
	}
 
	ll base = uniform_int_distribution<int>(300, 1000000006)(rng);
 
	ll mod1 = 1000000007LL;
 
	StringHashQuick helper(values[0], base, mod1, bigString.size());
 
	string answer = values[0];
 
	for (int i = 1; i < n; i++) {
 
		StringHashQuick helper2(values[i], base, mod1, values[i].size());
 
 
		int best = 0;
		for (int j = 0; j < min((int)values[i].size(), helper.curLength); j++) {
			int hash1 = helper2.getHash(0, j);
			int hash2 = helper.getHash(helper.curLength - 1 - j, helper.curLength - 1);
 
			//cout << "helper cur length is " << helper.curLength << endl;
			//cout << "got hashes " << hash1 << ' ' << hash2 << " at " << j << endl;
			if (helper2.getHash(0, j) == helper.getHash(helper.curLength - 1 - j, helper.curLength - 1)) {
				best = j + 1;
			}
		}
		//cout << "Checking " << i << " as " << answer << ' ' << values[i] << " got common " << best << endl;
 
		string thisAnswer = "";
		for (int j = 0; j < values[i].size(); j++) {
			if (j >= best) {
				//Include this in the result
				thisAnswer += values[i][j];
			}
		}
 
		//cout << i << " add " << thisAnswer << "yay"  << " size is " << thisAnswer.size()<< endl;
 
		answer += thisAnswer;
 
		//cout << "answer is " << answer << endl;
 
		helper.concat(thisAnswer);
	}
 
	cout << answer << endl;
}
 
//don't do dumb stuff with merge-sort tree like using update when everything is static...
 
//IF IT'S MATH THE ANSWER IS IN THE GCD, GCD THE INPUTS, OR WHATEVER USE GCD
//CAST .SIZE() TO INT!!!!
 
//PRO TIP: THE BEST WAY TO SOLVE THE PROBLEM IS TO HAVE THE RIGHT ANSWER!