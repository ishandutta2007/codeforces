#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int cnt[200005];
vector<int> v;
int ans;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (i!=m) {
            if (!a[i]) a[i]=n+2;
            ++cnt[a[i]];
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end());
    int last=v.size()-1;
    int last2=0;
    if (a[m]) ++ans;
    if (cnt[0]) {
        ++last2;
        --cnt[0];
        ++ans;
    }
    while (last>=0) {
        if (cnt[last2+1]) {
            --cnt[last2+1];
            ++last2;
            continue;
        } else {
            if (v[last]<=last2+1) break;
            --last;
            ++last2;
            ++ans;
            continue;
        }
    }
    ans+=cnt[0];
    cout<<ans;
}