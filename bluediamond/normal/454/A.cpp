#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int x=n/2;
    int y=1;
    vector<string>ans;
    while(y<=n) {
        string acm;
        for(int i=1;i<=x;i++)acm+="*";
        for(int i=1;i<=y;i++)acm+="D";
        for(int i=1;i<=x;i++)acm+="*";
        cout<<acm<<"\n";
        ans.push_back(acm);
        x--;
        y+=2;
    }
    for(int i=ans.size()-2;i>=0;i--) {
        cout<<ans[i]<<"\n";
    }
    return 0;
}