#include <bits/stdc++.h>
using namespace std;




int n,m;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (m%2==0) {
        cout<<"YES"<<'\n';
        m/=2;
        for (int i=1;i<=n;++i)
            cout<<".";
        cout<<'\n';
        cout<<".";
        for (int i=1;i<=m;++i)
            cout<<"#";
        for (int i=2+m;i<=n;++i)
            cout<<".";
        cout<<'\n';
        cout<<".";
        for (int i=1;i<=m;++i)
            cout<<"#";
        for (int i=2+m;i<=n;++i)
            cout<<".";
        cout<<'\n';
        for (int i=1;i<=n;++i)
            cout<<".";
        return 0;
    }
    if (m>=n-2) {
    cout<<"YES"<<'\n';
    for (int i=1;i<=n;++i)
        cout<<".";
    cout<<'\n';
    cout<<".";
    for (int i=2;i<n;++i)
        cout<<"#";
    cout<<"."<<'\n';
    string res="";
    m-=n-2;
    if (!m) {
        for (int i=1;i<=n;++i)
            res+=".";
        cout<<res<<'\n';
        cout<<res<<'\n';
        return 0;
    }
    res=".#";
    for (int i=3;i<=n;++i)
        res+=".";
    res[n-2]='#';
    m-=2;
    int last=n-3;
    while (m--) {
        res[last--]='#';
    }
    cout<<res<<'\n';
    for (int i=1;i<=n;++i)
        cout<<".";
    return 0;
    }
    if (m>=5) {
        cout<<"YES"<<'\n';
        for (int i=1;i<=n;++i)
            cout<<".";
        cout<<'\n';
        cout<<".#.#";
        int x=(m-5)/2;
        for (int i=1;i<=x;++i)
            cout<<"#";
        for (int i=5+x;i<=n;++i)
            cout<<".";
        cout<<'\n';
        cout<<".###";
        for (int i=1;i<=x;++i)
            cout<<"#";
        for (int i=5+x;i<=n;++i)
            cout<<".";
        cout<<'\n';
        for (int i=1;i<=n;++i)
            cout<<".";
        return 0;
    }
    if (m==1) {
        cout<<"YES"<<'\n';
        for (int i=1;i<=n;++i)
            cout<<".";
        cout<<'\n';
        string s1="";
        for (int i=1;i<=n;++i)
            s1+=".";
        string s2=s1;
        s2[n/2]='#';
        cout<<s2<<'\n';
        cout<<s1<<'\n';
        cout<<s1<<'\n';
        return 0;
    }
        cout<<"YES"<<'\n';
        for (int i=1;i<=n;++i)
            cout<<".";
        cout<<'\n';
        string s1="";
        for (int i=1;i<=n;++i)
            s1+=".";
        string s2=s1;
        s2[n/2]='#';
        s2[n/2-1]='#';
        s2[n/2+1]='#';
        cout<<s2<<'\n';
        cout<<s1<<'\n';
        cout<<s1<<'\n';
        return 0;

}