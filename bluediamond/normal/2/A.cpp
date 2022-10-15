#include <bits/stdc++.h>

using namespace std;

map<string,int>s;
map<string,int>s2;
map<string,int>when;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string>a(n);
    vector<int>x(n);
    for(int i=0;i<n;i++) {
        cin>>a[i]>>x[i];
        s[a[i]]+=x[i];
    }
    for(int i=0;i<n;i++) {
        s2[a[i]]+=x[i];
        if(when[a[i]]==0 && s2[a[i]]>=s[a[i]])
            when[a[i]]=i+1;
    }
    string ans="@";
    s[ans]=-1;
    for(int i=0;i<n;i++) {
        if(s[a[i]]>s[ans])
            ans=a[i];
        else
            if(s[a[i]]==s[ans] && when[a[i]]<=when[ans])
                ans=a[i];
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/