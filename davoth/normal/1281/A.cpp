#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int main() {
    fast_io;
    ll n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int sz=s.size();
        if(s[sz-2]=='p' && s[sz-1]=='o') cout << "FILIPINO\n";
        else if((s[sz-4]=='d' && s[sz-3]=='e' || s[sz-4]=='m' && s[sz-3]=='a') && s[sz-2]=='s' && s[sz-1]=='u') cout << "JAPANESE\n";
        else cout << "KOREAN\n";
    }
    return 0;
}