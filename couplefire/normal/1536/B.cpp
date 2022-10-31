#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    vector<string> one, two, three;
    for(int i = 0; i<26; i++) one.push_back(string{char('a'+i)});
    for(int i = 0; i<26; i++)
        for(int j = 0; j<26; j++) two.push_back(string{char('a'+i), char('a'+j)});
    for(int i = 0; i<26; i++)
        for(int j = 0; j<26; j++)
            for(int k = 0; k<26; k++) three.push_back(string{char('a'+i), char('a'+j), char('a'+k)});
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        bool work = 0;
        for(string x : one){
            bool good = 1;
            for(int i = 0; i<(int)s.length(); i++)
                good &= (x!=s.substr(i, 1));
            if(good){
                cout << x << endl, work = 1;
                break;
            }
        }
        if(work) continue;
        for(string x : two){
            bool good = 1;
            for(int i = 0; i<(int)s.length()-1; i++)
                good &= (x!=s.substr(i, 2));
            if(good){
                cout << x << endl, work = 1;
                break;
            }
        }
        if(work) continue;
        for(string x : three){
            bool good = 1;
            for(int i = 0; i<(int)s.length()-2; i++)
                good &= (x!=s.substr(i, 3));
            if(good){
                cout << x << endl, work = 1;
                break;
            }
        }
        assert(work == 1);
    }
}