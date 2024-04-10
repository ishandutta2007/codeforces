#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string a;
int k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>k;
    int sz=a.size();
    int ans=0;
    for(int i=sz-1;i>=0;i--) {
        if(a[i]=='0') {
            k--;
            if(k==0) {
                cout<<ans<<"\n";
                return 0;
            }
        }
        else {
            ans++;
        }
    }
    cout<<sz-1<<"\n";
    return 0;
}