#include <bits/stdc++.h>
using namespace std;


int n;
int a[100005];
bool f[6000005];
bool used[6000005];
int last[6000005];

inline void init() {
    for (int i=2;i<=6000000;++i) if (!f[i]) {
        last[i]=i;
        for (int j=i+i;j<=6000000;j+=i) f[j]=true,last[j]=i;
    }
    for (int i=2;i<=6000000;++i)
    if (!f[i]) last[i]=i;
}

inline bool check(int x) {
    while (x>1) {
        if (used[last[x]]) return false;
        x/=last[x];
    }
    return true;
}

inline void add(int x) {
    while (x>1) {
        used[last[x]]=true;
        x/=last[x];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    init();
    int last=2;
    for (int i=1;i<=n;++i) {
        if (check(a[i])) {
            cout<<a[i]<<" ";
            add(a[i]);
            continue;
        }
        last=a[i];
        for (int j=i;j<=n;++j) {
            while (true) {
                if (check(last)) {
                    cout<<last<<" ";
                    add(last);
                    ++last;
                    break;
                }
                ++last;
            }
            if (j==i) last=2;
        }
        break;
    }
}