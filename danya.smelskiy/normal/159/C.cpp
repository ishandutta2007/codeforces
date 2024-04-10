#include <bits/stdc++.h>
using namespace std;




int k;
string s;
int n;
vector<int> v[30];
vector<int> vv[30];
int t[1000005];
char ans[1000005];


void f(int l,int r,int x,int y) {
    if (l==r) {
        t[x]--;
        return;
    }
    int mid=(l+r)>>1;
    if (t[x+x]>=y) f(l,mid,x+x,y);
    else f(mid+1,r,x+x+1,y-t[x+x]);
    t[x]=t[x+x]+t[x+x+1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k;
    cin>>s;
    n=s.size();
    s="#"+s;
    int len=0;
    while (k--) {
        for (int i=1;i<=n;++i) {
            int x=s[i]-'a';
            v[x].push_back(len+i);
        }
        len+=n;
    }
    int m;
    cin>>m;
    while (m--) {
        int x;
        char c;
        cin>>x>>c;
        vv[c-'a'].push_back(x);
    }
    int sz=1;
    while (sz<len) sz+=sz;
    for (int i=0;i<26;++i) {
        memset(t,0,sizeof(t));
        for (int j=0;j<v[i].size();++j) {
            t[sz+v[i][j]-1]++;
        }
        for (int i=sz-1;i>0;--i)
            t[i]=t[i+i]+t[i+i+1];
        for (int j=0;j<vv[i].size();++j) {
            f(1,sz,1,vv[i][j]);
        }
        for (int j=0;j<v[i].size();++j) {
            if (t[sz+v[i][j]-1]) ans[v[i][j]]=char(i+'a');
        //    if (t[sz+v[i][j]-1]) cout<<v[i][j]<<" "<<char(i+'a')<<'\n';
        }
    }
    for (int i=1;i<=len;++i)
        if (ans[i]) cout<<ans[i];

}