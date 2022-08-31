#include <bits/stdc++.h>
using namespace std;

struct Suffix_Automaton{
    struct state{
        map<char, int> c;
        int link;
        int len;
    };
    vector<state> s;
    int last;

    void add_char(char const&c){
        int r = s.size();
        s.push_back(state{{}, 0, s[last].len+1});
        int p = last;
        for(;p>=0 && !s[p].c.count(c);p=s[p].link){
            s[p].c[c] = r;
        }
        if(p>=0){
            int q = s[p].c[c];
            if(s[q].len == s[p].len+1){
                s[r].link = q;
            } else {
                int qq = s.size();
                s.push_back(s[q]);
                s.back().len = s[p].len+1;
                s[q].link = qq;
                s[r].link = qq;
                for(;p>=0 && s[p].c[c] == q;p=s[p].link){
                    s[p].c[c] = qq;
                }
            }
        }
        last = r;
    }
    Suffix_Automaton():s(1, state{{}, -1, 0}), last(0){}
    void print(){
        for(int i=0;i<(int)s.size();++i){
            cerr << i << " : " << s[i].link << " " << s[i].len << "\n";
            for(auto &e:s[i].c){
                cerr << "   " << e.first << " " << e.second << "\n";
            }
        }
        cerr << "\n";
    }
};

signed main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        string ss;
        cin >> ss;
        Suffix_Automaton sa;
        for(auto &e:ss){
            sa.add_char(e);
        }
        int n = sa.s.size();
        vector<int> chs(n, 0);
        stack<int> s;
        vector<int> cnt(n, 0);
        for(int i=0, j=0;j!=sa.last;++i){
            ++cnt[j];
            j = sa.s[j].c[ss[i]];
        }
        ++cnt[sa.last];
        for(int i=1;i<n;++i){
            ++chs[sa.s[i].link];
        }
        for(int i=0;i<n;++i){
            if(chs[i] == 0) s.push(i);
        }
        while(!s.empty()){
            int a = s.top();
            s.pop();
            int b = sa.s[a].link;
            if(b>=0){
                cnt[b]+=cnt[a];
                if(--chs[b] == 0){
                    s.push(b);
                }
            }
        }
        long long ans = 0;
        for(int i=1;i<n;++i){
            ans+=cnt[i]*(long long)cnt[i] * (sa.s[i].len-sa.s[sa.s[i].link].len);
        }
        cout << ans << "\n";
    }
}