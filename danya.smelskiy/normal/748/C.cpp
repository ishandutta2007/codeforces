#include <bits/stdc++.h>
using namespace std;


int n;
string s;
bool used[5];
int ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    ans=1;
    for (int i=0;i<n;++i) {
        int x=0;
        if (s[i]=='L') x=0;
        else if (s[i]=='U') x=1;
        else if (s[i]=='R') x=2;
        else x=3;
        if (used[(x+2)%4]) {
            memset(used,false,sizeof(used));
            ++ans;
        }
        used[x]=true;
    }
    cout<<ans;
}