#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld,ld> line;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2;
char s[MN];
char t[4] = {'A','C','T','G'};
int main () {
    int n;
    scanf ("%d",&n);
    int ans = INT_MAX;
    scanf ("%s",s);
    for (int i = 0; i < n-3; i++) {
        int att = 0;
        for (int j = i; j <= i+3; j++) {
            att += min(min(abs(s[j] - t[j-i]),abs(s[j]+26-t[j-i])),t[j-i] + 26 - s[j]);
        }
        ans = min(ans,att);
    }
    printf ("%d\n",ans);
    return 0;
}