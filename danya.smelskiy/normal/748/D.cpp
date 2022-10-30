#include <bits/stdc++.h>
using namespace std;

int n,m;
map<string,int> mt;
int all;
multiset<int> sk[500005];
vector<string> v2;
int ans;

inline bool pal(string s) {
    int l=0;
    int r=s.size()-1;
    while (l<=r) {
        if (s[l]!=s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

inline int get_number(string s) {
    if (mt.count(s)) return mt[s];
    else return mt[s]=++all;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        string s;
        int x;
        cin>>s>>x;
        int y=get_number(s);
        sk[y].insert(-x);
        v2.push_back(s);
    }
    int mx=0;
    for (int i=0;i<v2.size();++i) {
        string s=v2[i];
        string ss=s;
        reverse(ss.begin(),ss.end());
        int x=get_number(s);
        if (sk[x].empty()) continue;
        int xx=*sk[x].begin();
        xx=-xx;
        sk[x].erase(sk[x].find(-xx));
        int y=get_number(ss);
        if (!sk[y].empty()) {
            int yy=*sk[y].begin();
            yy=-yy;
            sk[y].erase(sk[y].find(-yy));
            if (xx+yy>=0) {
                ans+=xx+yy;
                if (pal(s)) mx=max(mx,-min(xx,yy));
            } else if (pal(s)) mx=max(mx,max(xx,yy));
        } else if (pal(s)) mx=max(mx,xx);
    }
    cout<<ans+mx;
}