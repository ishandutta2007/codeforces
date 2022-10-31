#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    set<int> cs;
    vector<int> occ(26, 0);
    for(auto c : s){
        cs.insert(c-'a');
        occ[c-'a']++;
    }
    for(auto c : cs)
        if(occ[c] == 1) return 1;
    return 0;
}

void solve(){
    string s; cin >> s;
    int n = s.length();
    if(check(s)){
        vector<int> occ(26, 0);
        for(auto c : s)
            occ[c-'a']++;
        char blah = 'z';
        for(int i = 0; i<26; i++)
            if(occ[i] == 1) blah = min(blah, char('a'+i));
        sort(s.begin(), s.end());
        int pos = 0;
        for(int i = 0; i<(int)s.length(); i++)
            if(s[i] == blah) pos = i;
        cout << blah;
        for(int i = 0; i<(int)s.length(); i++)
            if(i != pos) cout << s[i];
        cout << '\n'; 
    } else{
        vector<int> occ(26, 0);
        int good = 26;
        for(auto c : s)
            occ[c-'a']++;
        for(int i = 0; i<26; i++){
            if(occ[i] == 0) continue;
            good = min(good, i);
        }
        vector<int> oc;
        for(auto c : s)
            if(c-'a' != good) oc.push_back(c-'a');
        sort(oc.begin(), oc.end());
        reverse(oc.begin(), oc.end());
        vector<int> chunks;
        int tot = occ[good];
        if(tot > (int)oc.size()+2){
            int cntoc = 0;
            for(int i = 0; i<26; i++)
                if(i != good && occ[i]) cntoc++;
            if(cntoc == 0){
                for(int i = 0; i<occ[good]; i++)
                    cout << char('a'+good);
                cout << '\n';
                return;
            } else if(cntoc == 1){
                cout << char('a'+good);
                while(oc.size()) cout << char('a'+oc.back()), oc.pop_back();
                for(int i = 0; i<occ[good]-1; i++)
                    cout << char('a'+good);
                cout << '\n';
                return;
            } else{
                int cur = oc.back();
                cout << char('a'+good);
                cout << char('a'+cur);
                for(int i = 0; i<occ[good]-1; i++)
                    cout << char('a'+good);
                oc.pop_back();
                int nxt = 26;
                for(auto c : oc)
                    if(c != cur) nxt = min(nxt, c);
                oc.erase(find(oc.begin(), oc.end(), nxt));
                cout << char('a'+nxt);
                while(oc.size()) cout << char('a'+oc.back()), oc.pop_back();
                cout << '\n';
                return;
            }
        }
        chunks.push_back(2); tot -= 2;
        while(tot--) chunks.push_back(1);
        for(auto x : chunks){
            for(int i = 0; i<x; i++)
                cout << char('a'+good);
            if(oc.size()) cout << char('a'+oc.back()), oc.pop_back();
        }
        while(oc.size()) cout << char('a'+oc.back()), oc.pop_back();
        cout << '\n';
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}