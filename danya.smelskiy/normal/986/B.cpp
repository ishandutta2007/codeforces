#include <bits/stdc++.h>
using namespace std;


int n,res;
int a[1000005];
int f[1000005];

long long ans;

inline int get(int x) {
    int res=0;
    while (x>=0) {
        res+=f[x];
        x=(x&(x+1))-1;
    }
    return res;
}

inline void update(int x) {
    while (x<=n) {
        f[x]++;
        x=(x|(x+1));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int x;
    for (int i=1;i<=n;++i) {
        cin>>x;
        ans+=(i-1)-get(x);
        update(x);
    }
    ans%=2;
    if (ans%2==n%2) cout<<"Petr";
    else cout<<"Um_nik";
}