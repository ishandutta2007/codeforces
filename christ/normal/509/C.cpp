#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MN = 2e5+3, MOD = 1e9+7;
#define all(x) (x).begin(),(x).end()
string last,s;
string cheapest (int sum) {
	string ret;
	if (!sum) ret = "0";
	while (sum) {
		int take = min(sum,9);
		ret = char(take+'0')+ret;
		sum -= take;
	}
	return ret;
}
int main () {
   	int n,lsum=0;
	scanf ("%d",&n);
	for (int ii = 1; ii <= n; ii++) {
		int sum;
		scanf ("%d",&sum);
		if (ii == 1) {
			s=cheapest(sum);
		} else if (sum > lsum){
			int canadd = 0; s = "";
			for (int i = last.size()-1; i >= 0; i--) {
				canadd += '9'-last[i];
				if (canadd >= sum-lsum) {
					canadd -= '9'-last[i];
					for (int j = i+1; j < last.size(); j++) s += '9';
					s = (char)(sum-lsum-canadd+last[i]) + s;
					for (int j = i-1; j >= 0; j--) s = last[j] + s;
					break;
				}
			}
			if (s == "") s = cheapest(sum);
		} else {
			s = ""; int ssf = 1;
			for (int i = 0; i < last.size(); i++) {
				//add here
				ssf += last[i]-'0';
				if (last[i] == '9') continue;
				int need = sum-ssf;
				if (need < 0) continue;
				string g = cheapest(need);
				if (g.size() + i + 1 <= last.size()) {
					s = "";
					for (int j = 0; j < i; j++) s += last[j];
					s += char(last[i] + 1);
					for (int j = 0; j < last.size()-g.size()-i-1; j++) s += '0';
					s += g;
				}
			}
			if (s == "") {
				string g = cheapest(sum-1);
				s = "1";
				for (int i = 0; i < last.size()-g.size(); i++) s += '0';
				s += g;
			}
		}
		printf ("%s\n",s.c_str());
		last = s; lsum = sum;
	}
	return 0;
}