
//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = -1;
const int MOD = -1;
#define rep(i,l,r) for (int i=l;i<r;i++)
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    int n = s.size(), t = 0, e = 0;
    rep(i, 0, n)
    t+=(s[i]=='1');
    rep(i, 0, n) {
        if(s[i]=='0'){
            cout<<0;
            continue;
        }
        if(s[i]=='2') {
            if(e){

            }
            else{
                while(t--)cout<<1;
                e=1;
            }
            cout<<2;
        }
    }
    if(e)return 0;
    while(t--) cout << 1;
    return 0;
}