#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
long long c[100005];
long long n,f,s,x,y;
int main(){
    cin>>n;
    for (int i=1;i<n;++i){
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=n;++i)
        cin>>c[i];
        bool t=false;
    for (int i=1;i<n;++i){
        x=a[i];
        y=b[i];
        if (c[x]!=c[y]){
            f=x;
            s=y;
            t=true;
        }
    }
    if (t==false){
        cout<<"YES";
        cout<<endl<<1;
        return 0;
    }
    t=false;
    for (int i=1;i<n;++i){
        x=a[i];
        y=b[i];
        if (x!=f && y!=f && c[x]!=c[y]){
            t=true;
            break;
        }
    }
    if (t==false){
            cout<<"YES"<<'\n';
        cout<<f;
        return 0;
    }
    t=false;
    for (int i=1;i<n;++i){
        x=a[i];
        y=b[i];
        if (x!=s && y!=s && c[x]!=c[y]){
            t=true;
            break;
        }
    }
    if (t==false){
        cout<<"YES"<<'\n'<<s;
        return 0;
    }
    cout<<"NO";
    return 0;
}