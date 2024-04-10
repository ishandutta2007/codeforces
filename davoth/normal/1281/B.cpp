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
        string a,b;
        cin >> a >> b;
        bool c=false;
        for(int o=0; o<min(a.size(),b.size()); o++){
            if(a[o]<b[o]) {
                cout << a << '\n';
                c = true;
                break;
            }else if(b[o]<a[o]) break;
        }
        if(c) continue;
        vector<char> d;
        for(char o : a) d.push_back(o);
        sort(d.begin(),d.end());
        for(int o=0; o<a.size(); o++){
            if(d[o]<a[o]){
                for(int j=a.size()-1; j>=0; j--){
                    if(a[j]==d[o]){
                        char t=a[o];
                        a[o]=a[j];
                        a[j]=t;
                        break;
                    }
                }
                break;
            }
        }
        c=false;
        for(int j=0; j<min(a.size(),b.size()); j++){
            if(a[j]<b[j]){
                cout << a << '\n';
                c=true;
                break;
            }else if(b[j]<a[j]){
                cout << "---" << '\n';
                c=true;
                break;
            }
        }
        if(!c) if(a.size()<b.size()) cout << a << '\n';
        else cout << "---\n";
    }
    return 0;
}