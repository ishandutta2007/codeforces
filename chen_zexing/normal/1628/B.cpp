#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
unordered_map <string,int> mp;
string s[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,f=0;
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=1;i<=n;i++){
            if(s[i].size()==1||s[i].size()==2&&s[i][0]==s[i][1]||s[i].size()==3&&s[i][0]==s[i][2])
                f=1;
        }
        if(f){
            puts("YES");
            continue;
        }
        for(int i=n;i>=1;i--){
            if(s[i].size()==2){
                string t="";
                t+=s[i][1],t+=s[i][0];
                if(mp[t]) f=1;
                for(int j=0;j<26;j++){
                    string temp=t;
                    temp=char(j+'a')+temp;
                    if(mp[temp]) f=1;
                }
            }
            else{
                string t="";
                t+=s[i][1],t+=s[i][0];
                if(mp[t]) f=1;
                t=s[i][2]+t;
                if(mp[t]) f=1;
            }
            mp[s[i]]=1;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//unordered_map
//cf