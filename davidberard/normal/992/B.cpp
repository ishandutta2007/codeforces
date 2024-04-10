#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> primes;

char sieve[32000];
void setup() {
	for(int i=2;i<32000;++i)  {
		if(sieve[i] == 0) {
			for(int j=i*i;j<32000;j+=i) {
				sieve[j] = 1;
			}
			primes.push_back(i);
		}
	}
}

ll gcd(ll a, ll b) {
	if(b ==0) return a;
	a%=b;
	return gcd(b, a);
}

vector<pii> factor(int x) {
	vector<pii> ans;
	if(x == 1) {
		//cerr << "..!" << endl;
		return ans;
	}
	for(int i=0;i<primes.size();++i) {
		if(x%primes[i] == 0) {
			int amt = 0;
			while(x%primes[i] == 0) {
				x /= primes[i];
				++amt;
			}
			//cerr << "pb" << endl;
			ans.push_back({primes[i], amt});
		}
	}
	if(x != 1) {
		ans.push_back({x, 1});
	}
	//cerr << ".. " << endl;
	return ans;
}
int l, r;

void dfs(int pos, vector<pii>& options, vector<int>& ans, int here) {
	if(pos == options.size()) {
		if(here <= r && here >= l) {
			ans.push_back(here);
		}
		return;
	}
	for(int i=0;i<=options[pos].second;++i) {
		dfs(pos+1, options, ans, here);
		here*= options[pos].first;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	setup();
	//cerr << "!!" << endl;
	int x, y;
	cin >> l;
	cin >> r;
	cin >> x;
	cin >> y;
	
	vector<pii> xf = factor(x), yf = factor(y);
	vector<pii> extra;
	// GCD = xf, LCM = y
	// expect all from gcd in lcm : gcd < lcm
	int j=0;
	for(int i=0;i<xf.size();++i) {
		//cerr << "i = " << i << endl;
		while(j < yf.size() && yf[j].first < xf[i].first) {
			//cerr << "j = " << j << endl;
			extra.push_back(yf[j]);
			++j;
		}
		if(j >= yf.size() || yf[j].first > xf[i].first || (yf[j].first == xf[i].first && yf[j].second < xf[i].second)) {
			cout << 0 << endl;
			return 0;
		}
		if(yf[j].second > xf[i].second) {
			extra.push_back(pii(xf[i].first, yf[j].second-xf[i].second));
		}
		++ j;
	}
	while(j < yf.size()) {
		extra.push_back(yf[j]);
		++j;
	}
	////cerr;for(int i=0;i<extra.size();++i) {
		////cerr << " " << extra[i].first << " " << extra[i].second << endl;
	////cerr;}
	////cerr << "SOMETHING ELSE " << endl;
	vector<int> answers;
	dfs(0, extra, answers, x);
	set<pii> fin;
	for(int i=0;i<answers.size();++i) {
		for(int j=0;j<answers.size();++j) {
			int g = gcd(answers[i], answers[j]);
			int lc = (ll) answers[i]*answers[j]/g;
			if(g == x && lc == y) {
				fin.insert(pii(answers[i], answers[j]));
			}
		}
	}
	cout << fin.size() << endl;


	return 0;
}