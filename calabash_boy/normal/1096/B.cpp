#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5+100;
char s[maxn];
int n;
int main(){
    cin>>n;
    cin>>s;
    if (n == 2){
        puts("3");
        return 0;
    }
    char lch = s[0],rch = s[n-1];
    int ans =0;
    int l = 0;
    while (s[l] == lch) l++;
    int r = 0;
    while (s[n-1 - r] == rch) r++;
    if (lch == rch)
    ans += 1ll * (l) * (r) % mod;
    (ans += l + r+1)%= mod;
    cout<<ans<<endl;
}