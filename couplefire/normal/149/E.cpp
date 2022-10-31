//https://codeforces.com/problemset/problem/149/E
#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
	struct state {
		int len = 0, firstPos = -1; bool isClone = 0;
		int link = -1; vector<int> invLink; 
		map<char, int> next;
	}; vector<state> st;
	int last = 0;
	void extend(char c) {
		int cur = st.size(); st.emplace_back();
		st[cur].len=st[last].len+1, st[cur].firstPos=st[cur].len-1;
		int p = last;
		while (p != -1 && !st[p].next.count(c)) 
			st[p].next[c] = cur, p = st[p].link;
		if (p == -1) st[cur].link = 0;
		else {
			int q = st[p].next[c];
			if (st[p].len+1 == st[q].len) st[cur].link = q;
			else { // new equivalence class
				int clone = st.size(); st.push_back(st[q]);
				st[clone].len = st[p].len+1, st[clone].isClone = 1;
                st[clone].firstPos = st[q].firstPos;
				while (p != -1 && st[p].next[c] == q) 
					st[p].next[c] = clone, p = st[p].link;
				st[q].link = st[cur].link = clone;
			} // first pos of longest[link[link[last]]] increases
		} // whenever transition is redirected, amortized linear
		last = cur; 
	}
	void init(string s) { 
		st.emplace_back(); for(auto x : s) extend(x); 
		for(int v = 1; v<st.size(); v++) st[st[v].link].invLink.push_back(v);
	}
	// APPLICATIONS
    vector<int> getFirstOccurs(string s){
        int cur = 0;
        vector<int> answers;
        for(auto x : s){
            if(!st[cur].next.count(x)) break;
            cur = st[cur].next[x];
            answers.push_back(st[cur].firstPos);
        }
        return answers;
    }
	void getAllOccur(vector<int>& oc, int v) {
		if (!st[v].isClone) oc.push_back(st[v].firstPos);
		for(auto u : st[v].invLink) getAllOccur(oc,u);
	}
	vector<int> allOccur(string s) {
		int cur = 0;
		for(auto x : s) {
			if (!st[cur].next.count(x)) return {};
			cur = st[cur].next[x];
		}
		vector<int> oc; getAllOccur(oc,cur); for(auto t : oc) t += 1-s.size();
		sort(oc.begin(), oc.end()); return oc;
	}
	vector<long long> distinct;
	long long getDistinct(int x) {
		if (distinct[x]) return distinct[x];
		distinct[x] = 1; 
		for(auto y:st[x].next) distinct[x] += getDistinct(y.second);
		return distinct[x];
	}
	long long numDistinct() { // # distinct substrings including empty
		distinct.resize(st.size()); return getDistinct(0); }
	long long numDistinct2() { // another way to do above
		long long ans = 1;
		for(int i=1; i<st.size(); i++) ans += st[i].len-st[st[i].link].len;
		return ans;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    int n = s.length();
    SuffixAutomaton straight;
    straight.init(s);
    reverse(s.begin(), s.end());
    SuffixAutomaton curve;
    curve.init(s);
    int m; cin >> m;
    int num = 0;
    while(m--){
        string s1; cin >> s1;
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<int> a1 = straight.getFirstOccurs(s1);
        vector<int> a2 = curve.getFirstOccurs(s2);
        if(a1.size() == s1.length()) a1.pop_back();
        if(a2.size() == s2.length()) a2.pop_back();
        for(int i= 0; i<a1.size(); i++){
            int index1 = a1[i];
            if(a2.size() <= s1.size()-i-2) continue;
            int index2 = s.size()-1-a2[s1.size()-i-2];
            if(index2-index1 >= 1){
                num++;
                break;
            }
        }
    }
    cout << num << endl;
}