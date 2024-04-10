#include <bits/stdc++.h>
using namespace std;


int n;
string s[105];
bool used[105];
int a[105];
vector<int> v;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    while (true) {
        int pos=-1;
        for (int i=1;i<=n;++i)
        if (!used[i] && a[i]==0) {
            pos=i;
            break;
        }
        if (pos==-1) break;
        used[pos]=true;
        for (int i=1;i<=n;++i)
            if (s[pos][i]=='1') --a[i];
    }
    for (int i=1;i<=n;++i)
        if (used[i]) v.push_back(i);
    cout<<v.size()<<'\n';
    for (auto it : v)
        cout<<it<<" ";
}