#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300000+5;
int n,v[N];
int nxt[N*31][2];
int cnt[N*31];
int total=0;

inline void add(int x) {
    int t=0;
    cnt[t]++;
    for(int i=30;i>=0;i--) {
        int bt=0;
        if(x&(1<<i)) {
            bt=1;
        }
        if(nxt[t][bt]==0) {
            total++;
            nxt[t][bt]=total;
        }
        t=nxt[t][bt];
        cnt[t]++;
    }
    return;
}

inline int slove(int x) {
    int t=0;
    cnt[t]--;
    int ans=0;
    for(int i=30;i>=0;i--) {
        int bt=0;
        if(x&(1<<i)) {
            bt=1;
        }
        if(nxt[t][bt]!=0) {
            int nou=nxt[t][bt];
            cnt[nou]--;
            if(cnt[nou]==0) {
                nxt[t][bt]=0;
            }
            if(bt==1) {
                ans+=(1<<i);
            }
            t=nou;
        }
        else {
            int nou=nxt[t][1-bt];
            cnt[nou]--;
            if(cnt[nou]==0) {
                nxt[t][1-bt]=0;
            }
            if(bt==0) {
                ans+=(1<<i);
            }
            t=nou;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        add(x);
    }
    for(int i=1;i<=n;i++) {
        int val=slove(v[i]);
        cout<<(val^v[i])<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

**/