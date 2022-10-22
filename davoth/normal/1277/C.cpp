#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int t;
int main() {
    fast_io;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.size()<3) {
            cout << 0 << '\n';
            continue;
        }
        int sz=s.size();
        bool mark[sz];
        fill(mark,mark+sz,false);
        for(int i=1; i<sz-1; i++){
            if(!mark[i] && !mark[i-1] && !mark[i+1] && s[i]=='n' && s[i-1]=='o' && s[i+1]=='e') mark[i]=true;
            if(!mark[i] && !mark[i+1] && !mark[i-1] && s[i]=='w' && s[i-1]=='t' && s[i+1]=='o'){
                if(i+3<sz && s[i+2]=='n' && s[i+3]=='e') mark[i+1]=true;
                else mark[i]=true;
            }
        }
        vector<int> ans;
        for(int i=0; i<sz; i++) if(mark[i]) ans.push_back(i+1);
        cout << ans.size() << '\n';
        for(int i : ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}