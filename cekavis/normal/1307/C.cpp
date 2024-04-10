#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, C = 26;
int a[C];
ll ans, b[C][C];
char s[N];
int main(){
    scanf("%s", s);
    for(int i=0; s[i]; ++i){
        for(int j=0; j<C; ++j) b[j][s[i]-'a']+=a[j];
        ++a[s[i]-'a'];
    }
    for(int i=0; i<C; ++i) ans=max(ans, (ll)a[i]);
    for(int i=0; i<C; ++i) for(int j=0; j<C; ++j) ans=max(ans, b[i][j]);
    printf("%lld\n", ans);
    return 0;
}