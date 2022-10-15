#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+5;

int n,v[N];
int p,st[N],dr[N];
int cur=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    bool ok=0;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        if(v[i]!=0)
            ok=1;
    }
    if(ok==0) {
        cout<<"NO\n";
        return 0;
    }
    p=1;
    st[p]=dr[p]=1;
    for(int i=1;i<=n;i++) {
        if(v[i]==0) {
            dr[p]=i;
            continue;
        }
        else {
            cur++;
            if(cur==2) {
                cur=1;
                p++;
                st[p]=dr[p]=i;
            }
            else
                dr[p]=i;
        }
    }
    cout<<"YES\n";
    cout<<p<<"\n";
    for(int i=1;i<=p;i++) {
        cout<<st[i]<<" "<<dr[i]<<"\n";
    }
    return 0;
}
/**

**/