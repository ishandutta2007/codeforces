#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin>>n;
    if (n==1) {
        cout<<"a\na\nb\nb";
        return 0;
    }
    if (n==2) {
        cout<<"aa\nbb\naa\nbb";
        return 0;
    }
    if (n&1) {
        for (int i=1;i<=n/2;++i)
            if (i&1) cout<<"aa";
            else cout<<"bb";
        cout<<"c"<<'\n';
        for (int i=1;i<=n/2;++i)
            if (i&1) cout<<"bb";
            else cout<<"aa";
        cout<<"c"<<'\n';
        cout<<"d";
        for (int i=1;i<=n/2;++i)
            if (i&1) cout<<"ee";
            else cout<<"ff";
        cout<<'\n';
        cout<<"d";
        for (int i=1;i<=n/2;++i)
            if (i&1) cout<<"ff";
            else cout<<"ee";
        return 0;
    }
    for (int i=1;i<=n/2;++i)
        if (i&1) cout<<"aa";
        else cout<<"bb";
    cout<<'\n';
    for (int i=1;i<=n/2;++i)
        if (i&1) cout<<"bb";
        else cout<<"aa";
    cout<<'\n';
    cout<<"c";
    for (int i=1;i<=n/2-1;++i)
        if (i&1) cout<<"dd";
        else cout<<"ee";
    cout<<"f"<<'\n';
    cout<<"c";
    for (int i=1;i<=n/2-1;++i)
        if (i&1) cout<<"ee";
        else cout<<"dd";
    cout<<"f"<<'\n';
}