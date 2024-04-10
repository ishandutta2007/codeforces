#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=105;
bool a[N];
bool b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int len;
    cin>>len;
    for(int i=1;i<=len;i++) {
        int x;
        cin>>x;
        a[x]=1;
    }
    cin>>len;
    for(int i=1;i<=len;i++) {
        int x;
        cin>>x;
        b[x]=1;
    }
    int x=0,y=0;
    for(int i=0;i<=(int)1e8;i++) {
        if(a[x] || b[y]) {
            a[x]=b[y]=1;
        }
        x++;
        y++;
        if(x==n)
            x=0;
        if(y==m)
            y=0;
    }
    for(int i=0;i<n;i++)
        if(a[i]==0) {
            cout<<"No\n";
            return 0;
        }
    for(int i=0;i<m;i++)
        if(b[i]==0) {
            cout<<"No\n";
            return 0;
        }
    cout<<"Yes\n";
    return 0;
}