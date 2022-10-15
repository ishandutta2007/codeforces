#include <bits/stdc++.h>

using namespace std;

int auxx=0;

string gt() {
    if(auxx<26) {
        string ans;
        ans+=char('A'+auxx);
        auxx++;
        return ans;
    }
    string ans;
    ans+=char('A'+auxx/26-1);
    ans+=char('a'+auxx%26);
    auxx++;
    return ans;
}

const int N=50+5;
int n;
bool eg[N];
string ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=n-l+1;i++) {
        string a;
        cin>>a;
        if(a=="NO")
            eg[i]=1;
    }
    for(int i=1;i<=n;i++) {
        ans[i]=gt();
    }
    for(int i=1;i<=n;i++) {
        if(eg[i]) {
            ans[i+l-1]=ans[i];
        }
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}