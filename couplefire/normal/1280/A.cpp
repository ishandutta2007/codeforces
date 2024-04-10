#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        string s; cin >> s;
        vector<int> text(max(x+5,(int)s.length()));
        for(int i = 0; i<s.length(); i++) text[i] = s[i]-'0';
        int len = s.length();
        int cur = s.length();
        for(int i = 0; i<x; i++){
            len = (0ll+len+1ll*(len-i-1)*(text[i]-1))%MOD;
            int curlen = cur-i-1;
            for(int j = 0; j<text[i]-1; j++){
                int num = 0;
                while(cur < text.size() && num < curlen){
                    text[cur] = text[cur-curlen];
                    cur++;
                    num++;
                }
            }
        }
        if(len < 0) len+=MOD;
        cout << len << endl;
    }
}