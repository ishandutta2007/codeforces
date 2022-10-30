#include <bits/stdc++.h>
using namespace std;



int n,m;
int sz;
long long t[500005];
long long ob[500005];
long long a[500005];
string s;


long long get(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return 1e15;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    if (ob[x]) {
        ob[x+x]+=ob[x];
        ob[x+x+1]+=ob[x];
        t[x+x]+=ob[x];
        t[x+x+1]+=ob[x];
        ob[x]=0;
    }
    return min(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1));
}

void update(int l,int r,int ll,int rr,int x,int y) {
    if (l>r || ll>r || l>rr || ll>rr) return;
    if (l>=ll && r<=rr) {
        t[x]+=y;
        ob[x]+=y;
        return;
    }
    int mid=(l+r)>>1;
    if (ob[x]) {
        ob[x+x]+=ob[x];
        ob[x+x+1]+=ob[x];
        t[x+x]+=ob[x];
        t[x+x+1]+=ob[x];
        ob[x]=0;
    }
    update(l,mid,ll,rr,x+x,y);
    update(mid+1,r,ll,rr,x+x+1,y);
    t[x]=min(t[x+x],t[x+x+1]);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i)
        t[sz+i-1]=a[i];
    for (int i=sz-1;i>0;--i)
        t[i]=min(t[i+i],t[i+i+1]);
    cin>>m;
    getline(cin,s);
    while (m--) {
        getline(cin,s);
        s+=" ";
        vector<long long > num;
        int last=0;
        for (int i=0;i<s.size();++i) {
            if (s[i]==' ') num.push_back(last),last=0;
            else if (s[i]!='-') last=(last*10+(s[i]-'0'));
        }
        int cur_cnt=0;
        for (int i=0;i<s.size();++i) {
            if (s[i]==' ') ++cur_cnt;
            else if (s[i]=='-') num[cur_cnt]*=-1;
        }
        if (num.size()==2)  {
            int x=num[0];
            int y=num[1];
            ++x;
            ++y;
            if (x<=y) cout<<get(1,sz,x,y,1)<<'\n';
            else cout<<min(get(1,sz,x,n,1),get(1,sz,1,y,1))<<'\n';
        } else {
            int x=num[0];
            int y=num[1];
            ++x;
            ++y;
            int z=num[2];
            if (x<=y) update(1,sz,x,y,1,z);
            else update(1,sz,x,n,1,z),update(1,sz,1,y,1,z);
        }
    }
}