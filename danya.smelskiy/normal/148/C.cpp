#include <bits/stdc++.h>
using namespace std;


int a,b,n;
int sz;
int ans[10005];

inline void check() {
    int s=ans[1];
    int last=ans[1];
    for (int i=2;i<=sz;++i) {
        if (ans[i]>s) { --b; }
        else if (ans[i]>last) --a;
        s+=ans[i];
        last=max(last,ans[i]);
    }
    if (a || b) {
        cout<<"-1";
        exit(0);
    }
    for (int i=1;i<=sz;++i)
        cout<<ans[i]<<" ";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    if (!b) {
        if (!a) {
            for (int i=1;i<=n;++i)
                cout<<"1 ";
            return 0;
        }
        if (n<a+2) {
            cout<<"-1";
            return 0;
        }
        ans[++sz]=2;
        ans[++sz]=2;
        int last=2;
        int aa=a;
        --n;
        --n;
        while (aa--) {
            n--;
            ans[++sz]=++last;
        }
        while (n--) {
            ans[++sz]=1;
        }
        check();
    }
    if (1+a+b>n) {
        cout<<"-1";
        return 0;
    }
    ans[++sz]=1;
    int s=1;
    for (int i=1;i<=b;++i) {
        ans[++sz]=s+1;
        if (i<b) s=s+s+1;
        else ++s;
    }
    for (int i=1;i<=a;++i) {
        ans[++sz]=++s;
    }
    n-=a+b+1;
    while (n--) {
        ans[++sz]=1;
    }
    check();

}