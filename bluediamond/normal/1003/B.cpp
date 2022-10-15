#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string tr(int x,int a,int b,int k) {
    int len=a+b;
    string ans;
    for(int i=2;i<=len;i++) {
        if(x==0) {
            a--;
            ans+="0";
        }
        else {
            ans+="1";
            b--;
        }
        int n0,n1;
        if(x==0) {
            n1=k/2+k%2;
            n0=k-n1;
        }
        else {
            n0=k/2+k%2;
            n1=k-n0;
        }
        if(x==0) {
            if(a==n0) {
                k--;
                x=1;
            }
            continue;
        }
        if(x==1) {
            if(b==n1) {
                k--;
                x=0;
            }
            continue;
        }
    }
    if(x==0)
        ans+="0";
    else
        ans+="1";
    return ans;
}

bool ok(string ans,int a,int b,int cnt) {
    for(int i=0;i<ans.size();i++) {
        if(ans[i]=='0')
            a--;
        else
            b--;
        if(i && ans[i]!=ans[i-1])
            cnt--;
    }
    if(a==0 && b==0 && cnt==0)
        return 1;
    return 0;
}

/**

k = 1

0 1

k = 2

0 1 0

**/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,k;
    cin>>a>>b>>k;
    string ans=tr(0,a,b,k);
    if(ok(ans,a,b,k)) {
        cout<<ans<<"\n";
        return 0;
    }
    cout<<tr(1,a,b,k)<<"\n";
    return 0;
}