#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+5;
int n;
string a[N];
int cnt[11]; /// cnt[val][poz]
bool nu[11];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        nu[a[i][0]-'a']=1;
    }
    for(int i=1;i<=n;i++) {
        int id=1;
        for(int j=a[i].size()-1;j>=0;j--) {
            cnt[a[i][j]-'a']+=id;
            id*=10;
        }
    }
    int ma=0;
    for(int i=0;i<10;i++) {
        if(nu[i]) {
            continue;
        }
        ma=max(ma,cnt[i]);
    }
    ll ans=0;
    for(int i=0;i<10;i++) {
        if(nu[i]) {
            continue;
        }
        if(cnt[i]==ma) {
            cnt[i]=-1;
            break;
        }
    }
    for(int x=1;x<=9;x++) {
        ma=0;
        for(int i=0;i<10;i++) {
            ma=max(ma,cnt[i]);
        }
        for(int i=0;i<10;i++) {
            if(ma==cnt[i]) {
                ans+=(ll)cnt[i]*x;
                cnt[i]=-1;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}

/**



**/