#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

bool does(string const&a, string const&b){
    int n = a.size();
    set<char> rev;
    for(auto const&e:a){
        rev.insert(e);
    }
    for(int i=0;i<n;++i){
        if(a[i]=='*'){
            if(rev.count(b[i])) return false;
        } else {
            if(a[i]!=b[i]) return false;
        }
    }
    return true;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n,m;
    cin >> n;
    string s;
    cin >> s;
    cin >> m;
    vector<string> a(m);
    for(auto &e:a) cin >> e;
    bitset<26> can;
    for(int i=0;i<26;++i) can[i] = 1;
    for(auto const&e:s){
        if(e!='*'){
            can[e-'a'] = 0;
        }
    }
    for(auto const&e:a){
        if(does(s, e)){
            bitset<26> c2;
            for(int i=0;i<n;++i){
                if(s[i] == '*'){
                    c2[e[i]-'a'] = 1;
                }
            }
            can = can&c2;
        }
    }
    cout << can.count() << '\n';

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}