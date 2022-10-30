#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<int> v1[1000005];
vector<int> v2[1000005];
int a[1000005];
int b[1000005];
bool used[1000005];
int ans;
void dfs1(int x){
    used[x]=true;
    for (int i=0;i<v1[x].size();++i) {
        int to=v1[x][i];
        if (used[to]==false) dfs1(to);
    }
}
void dfs2(int x){
    used[x]=true;
    for (int i=0;i<v2[x].size();++i) {
        int to=v2[x][i];
        if (used[to]==false) dfs2(to);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    for (int i=0;i<s.size();++i) {
        if (s[i]=='0') {
            a[(i+1)%n]++;
            b[i]++;
            v1[i].push_back((i+1)%n);
            v2[(i+1)%n].push_back(i);
        } else {
            a[i]++;
            b[(i+1)%n]++;
            v1[(i+1)%n].push_back(i);
            v2[i].push_back((i+1)%n);
        }
    }
    for (int i=0;i<n;++i)
    if (used[i]==false && a[i] && b[i]) {
        dfs1(i);
        dfs2(i);
        ++ans;
    }
    for (int i=0;i<n;++i)
    if (used[i]==false) {
        dfs1(i);
        dfs2(i);
        ans++;
    }
    cout<<ans;
}