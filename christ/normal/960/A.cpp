    #include <bits/stdc++.h>
    using namespace std;
    int main() {
    	string s;
    	cin >> s;
    	if (!is_sorted(s.begin(),s.end())) return !printf ("NO\n");
    	vector<int> cnt(256);
    	for (char c : s) cnt[c]++;
    	if ((cnt['c'] != cnt['a'] && cnt['c'] != cnt['b']) || !cnt['a'] || !cnt['b']) printf ("NO\n");
    	else printf ("YES\n");
        return 0;
    }