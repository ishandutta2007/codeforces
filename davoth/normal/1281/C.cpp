#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int main() {
    fast_io;
    int t;
    cin >> t;
    while(t--){
        int x;
        string s;
        cin >> x >> s;
        ll sz=s.size();
        string s2=s;
        bool c=true;
        for(int i=1; i<=x; i++){
            int kp=s[i-1]-'1';
            if(sz>x) c=false;
            if(c){
                s2.erase(s2.begin());
                string s3=s2;
                for(int j=0; j<kp; j++) s2+=s3,s+=s3;
            }
            int lsz=sz+1e9+7-i;
            for(int i=0; i<kp; i++) sz+=lsz,sz%=(ll)1e9+7;
        }
        cout << sz << '\n';
    }
    return 0;
}