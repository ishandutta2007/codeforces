#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
char s[maxn];
int succ1[maxn];
int succ2[maxn];
int main(){
    cin>>s;
    int n = strlen(s);
    for (int i=1;i<n;i++){
        succ1[i] = succ1[i-1] + (s[i] == 'v' && s[i-1] == 'v');
    }
    for (int i=n-2;i>=0;i--){
        succ2[i] = succ2[i+1] + (s[i] == 'v' && s[i+1] == 'v');
    }
    long long ans = 0;
    for (int i=2;i<n-2;i++){
        ans += 1ll * (s[i] == 'o') * succ1[i-1] * succ2[i+1];
    }
    
    cout<<ans<<endl;
    return 0;
}