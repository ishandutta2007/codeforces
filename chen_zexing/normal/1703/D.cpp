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
map <string,int> mp;
string s[100005];
int main() {
    ios::sync_with_stdio(false);
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        mp.clear();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i],mp[s[i]]=1;
        for(int i=1;i<=n;i++){
            int f=0;
            for(int j=0;j+1<s[i].size();j++){
                string t1="",t2="";
                for(int k=0;k<=j;k++) t1+=s[i][k];
                for(int k=j+1;k<s[i].size();k++) t2+=s[i][k];
                if(mp[t1]&&mp[t2]){
                    f=1;
                    break;
                }
            }
            cout<<f;
        }
        cout<<endl;
    }
    return 0;
}
//unordered_map
//cf