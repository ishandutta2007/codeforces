#include <bits/stdc++.h>
using namespace std;


int n;
int a[100005];
pair<int,int> b[100005];
int p[100005];
int pos;
int sz[100005];
multiset<int> s;
bool used[100005];
int ans;

int get(int x) {
    if (x==p[x]) return x;
    return p[x]=get(p[x]);
}

int x,y;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        b[i]=make_pair(a[i],i);
    }
    for (int i=1;i<=n;++i) {
        p[i]=i;
        sz[i]=1;
    }
    sort(b+1,b+n+1);
    b[n+1]=make_pair(b[n].first+1,1);
    for (int i=1;i<=n;++i) {
        x=b[i].second;
        used[x]=true;
        s.insert(1);
        if (used[x-1]) {
            y=get(x-1);
            p[y]=x;
            s.erase(s.find(sz[y]));
            s.erase(s.find(1));
            s.insert(sz[y]+1);
            sz[x]=sz[y]+1;
        }
        if (used[x+1]) {
            y=get(x+1);
            p[y]=x;
            s.erase(s.find(sz[y]));
            s.erase(s.find(sz[x]));
            s.insert(sz[x]+sz[y]);
            sz[x]=sz[x]+sz[y];
        }
        if (*s.begin()==*s.rbegin()) {
            if (s.size()>ans) {
                ans=s.size();
                pos=b[i].first+1;
            }
        }
    }
    cout<<pos;
}