#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
char go[26], cogo[26];
bool Free[26], cof[26];
int k;
void arb(){
    int u1 = 0, u2 = 0;
    while (u1 < k && u2 < k){
        if (go[u1] != '#') u1++;
        else if (!Free[u2]) u2++;
        else{
            go[u1] = (char) ('a' + u2);
            u1++, u2++;
        }
    }
    cout << "YES" << "\n";
    for (int i=0; i < k; i++) cout << go[i];
    cout << "\n";
}
bool first(string &s, string &a, int index){
    for (int i=index; i < a.size(); i++){
        int symb = s[i]-'a';
        if (go[symb] != '#'){
            if (go[symb] < a[i]){
                return false;
            }
            if (go[symb] == a[i]) continue;
            arb();
            return true;
        }
        bool good = false;
        for (char ch = (char) ('a'+k-1); ch >= a[i]; ch--){
            if (!Free[ch-'a']) continue;
            go[symb] = ch;
            Free[(int) (ch-'a')] = false;
            good = true;
            if (ch == a[i]) break;
            arb();
            return true;
        }
        if (!good) return false;
    }
    arb();
    return true;
}
bool second(string &s, string &b, int index){
    for (int i=index; i < b.size(); i++){
        int symb = s[i]-'a';
        if (go[symb] != '#'){
            if (go[symb] > b[i]){
                return false;
            }
            if (go[symb] == b[i]) continue;
            arb();
            return true;
        }
        bool good = false;
        for (char ch = 'a'; ch <= b[i]; ch++){
            if (!Free[ch-'a']) continue;
            go[symb] = ch;
            Free[ch-'a'] = false;
            good = true;
            if (ch == b[i]) break;
            arb();
            return true;
        }
        if (!good) return false;
    }
    arb();
    return true;
}
void solve(){
    cin >> k;
    string s, a, b;
    cin >> s >> a >> b;
    for (int i=0; i < 26; i++) go[i] = '#';
    for (int i=0; i < 26; i++) Free[i] = true;
    for (int i=0; i < a.size(); i++){
        int symb = s[i]-'a';
        if (a[i] == b[i]){
            if (go[symb] == '#'){
                if (Free[a[i]-'a']){
                    go[symb] = a[i];
                    Free[a[i]-'a'] = false;
                }
                else{
                    cout << "NO" << "\n";
                    return;
                }
            }
            else if (go[symb] != a[i]){
                cout << "NO" << "\n";
                return;
            }
        }
        else{
            if (go[symb] != '#'){
                if (go[symb] < a[i] || go[symb] > b[i]){
                    cout << "NO" << "\n";
                    return;
                }
                if (go[symb] == a[i]){
                    bool res = first(s, a, i+1);
                    if (!res) cout << "NO" << "\n";
                    return;
                }
                if (go[symb] == b[i]){
                    bool res = second(s, b, i+1);
                    if (!res) cout << "NO" << "\n";
                    return;
                }
                else{
                    arb();
                    return;
                }
            }
            else{
                for (char ch = a[i]+1; ch != b[i]; ch++){
                    if (!Free[ch-'a']) continue;
                    Free[ch-'a'] = false;
                    go[symb] = ch;
                    arb();
                    return;
                }
                if (Free[a[i]-'a']){
                    for (int j=0;j<k;j++) cogo[j] = go[j];
                    for (int j=0;j<k;j++) cof[j] = Free[j];
                    go[symb] = a[i];
                    Free[a[i]-'a'] = false;
                    bool res = first(s, a, i+1);
                    if (res) return;
                    for (int j=0;j<k;j++) go[j] = cogo[j];
                    for (int j=0;j<k;j++) Free[j] = cof[j];
                }
                if (Free[b[i]-'a']){
                    Free[b[i]-'a'] = false;
                    go[symb] = b[i];
                    bool res = second(s, b, i+1);
                    if (res) return;
                }
                cout << "NO" << "\n";
                return;
            }
        }
    }
    arb();
    return;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i=0; i < t; i++) solve();
    return 0;
}