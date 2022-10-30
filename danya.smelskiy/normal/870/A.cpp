#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100];
int b[100];

inline bool check(int x){
    bool t=false;
    bool tt=false;
    while (x>0) {
        int y=x%10;
        for (int i=1;i<=n;++i)
            if (a[i]==y) t=true;
        for (int i=1;i<=m;++i)
            if (b[i]==y) tt=true;
        if (t && tt) break;
        x/=10;
    }
    if (t && tt) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=m;++i)
        cin>>b[i];
    for (int i=1;;++i) {
        if (check(i)) {
            cout<<i;
            return 0;
        }
    }
}