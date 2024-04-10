#include <bits/stdc++.h>
using namespace std;


int n;
int a[200005];
pair<int,int> b[200005];

inline void no(){
    cout<<"NO";
    exit(0);
}

inline void check(int mm) {
    if (mm<=0) return;
    int nn=1e9;
    for (int i=1;i<=n;++i) {
        b[i].first=(a[i]+mm-1)/mm;
        nn=max(nn,b[i].first);
        b[i].second=(a[i]%mm);
        if (!b[i].second) b[i].second=mm;
    }
    int x,y;
    int nxt;
    for (int i=1;i<n;++i) {
        x=b[i].first;
        y=b[i].second;
        if (y<mm) {
            nxt=a[i]+1;
            if (nxt==a[i+1]) continue;
        }
        if (y>1) {
            nxt=a[i]-1;
            if (nxt==a[i+1]) continue;
        }
        if (x<nn) {
            nxt=a[i]+mm;
            if (nxt==a[i+1]) continue;
        }
        if (x>1) {
            nxt=a[i]-mm;
            if (nxt==a[i+1]) continue;
        }
        return;
    }
    cout<<"YES"<<'\n';
    cout<<nn<<" "<<mm;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (i>1 && a[i]==a[i-1]) no();
    }
    check(1);
    int res=0;
    for (int i=1;i<n;++i)
        res=max(res,abs(a[i+1]-a[i]));
    check(res);
    no();

}