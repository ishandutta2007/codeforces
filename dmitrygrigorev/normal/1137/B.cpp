#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
int z=0,o=0;
bool Try(string &answer, string &t){
    int nz = 0, no = 0;
    for (int i=0; i < t.size(); i++){
        if (t[i] == '0') nz++;
        else no++;
    }
    if (nz > z || no > o) return false;
    answer += t;
    z -= nz, o -= no;
    return true;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    for (int i=0; i < s.size(); i++){
        if (s[i] == '0') z++;
        else o++;
    }
    string T = t + '#' + t;
    vector<int> prf = z_function(T);
    int dop = t.size();
    int len = 1;
    //for (int i=0; i < prf.size(); i++) cout << prf[i] << endl;
    for (int i=t.size()+2; i < 2*t.size()+1; i++){
        if (prf[i] == (t.size() - len)){
            dop = len;
            break;
        }
        len++;
    }
    bool whole = true;
    string answer = "";
    string suff = "";
    for (int i=len; i >= 1; i--){
        suff += t[t.size()-i];
    }
    while (true){
        if (whole){
            bool res = Try(answer, t);
            if (!res) break;
            whole = false;
        }
        else{
            bool res = Try(answer, suff);
            if (!res) break;
        }
    }
    while (z > 0){
        answer += '0';
        z--;
    }
    while (o > 0){
        answer += '1';
        o--;
    }
    cout << answer;

}