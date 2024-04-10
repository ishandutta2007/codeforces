#include <bits/stdc++.h>
using namespace std;
int ans,f,p;
string s;
int n;
int t;


void update2(int x){
    if (x==0) {
        s="1"+s;
        return;
    }
    if (s[x-1]=='9') {
        s[x-1]='0';
        update2(x-1);
    } else s[x-1]=char(s[x-1]+1);
}
inline void update(int x){
    if (x==p) {
        update2(p-1);
        for (int i=1;i<=s.size();++i)
            if (s[i-1]=='.') break;
            else cout<<s[i-1];
        exit(0);
    }
    if (s[x-1]=='9') {
        ans=x-1;
        update(x-1);
    } else {
        s[x-1]=char(s[x-1]+1);
        if (s[x-1]>='5') f=x;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    cin>>s;
    for (int i=1;i<=n;++i)
        if (s[i-1]=='.') p=i;
        else if (p && !f && s[i-1]>='5') f=i;
    if (!f) {
        cout<<s;
        return 0;
    }
    while (f>p) {
        int xx=f;
        if (t==0) break;
        if (s[f-1]>='5') {
            --t;
            ans=f-1;
            update(f-1);
        }
        else --f;
        if (f==xx) --f;
    }
    for (int i=1;i<=ans;++i)
        cout<<s[i-1];
}