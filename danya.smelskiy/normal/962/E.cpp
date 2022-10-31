#include <bits/stdc++.h>
using namespace std;



int n;
long long ans;
int pos[200005];
char c[200005];

inline void solve(vector<pair<int,char> > v) {
    if (v.size()==1) return;
    if (v[0].second!='P' && v.back().second!='P') {
        int last1=-2e9,last2=-2e9;
        for (int i=0;i<v.size();++i) {
            if (v[i].second=='R') {
                if (last1!=-2e9) ans+=v[i].first-last1;
                last1=v[i].first;
            } else {
                if (last2!=-2e9) ans+=v[i].first-last2;
                last2=v[i].first;
            }
        }
        return;
    }
    if (v[0].second=='P' && v.back().second!='P') {
        int last1=v[0].first;
        int last2=last1;
        for (int i=0;i<v.size();++i) {
            if (v[i].second=='R') {
                ans+=v[i].first-last1;
                last1=v[i].first;
            } else {
                ans+=v[i].first-last2;
                last2=v[i].first;
            }
        }
        return;
    }
    if (v[0].second!='P' && v.back().second=='P') {
        int last1=v.back().first;
        int last2=v.back().first;
        for (int i=v.size()-2;i>=0;--i) {
            if (v[i].second=='R') {
                ans+=last1-v[i].first;
                last1=v[i].first;
            } else {
                ans+=last2-v[i].first;
                last2=v[i].first;
            }
        }
        return;
    }
    if (v.size()==2) {
        ans+=v.back().first-v[0].first;
        return;
    }
    bool t1=false,t2=false;
    for (int i=0;i<v.size();++i)
        if (v[i].second=='R') t1=true;
        else if (v[i].second=='B') t2=true;
    long long cur=0;
    cur+=v.back().first-v[0].first;
    cur+=v.back().first-v[0].first;
    if (!t1 || !t2) {
        ans+=v.back().first-v[0].first;
        ans+=v.back().first-v[0].first;
        long long mx1=0;
        long long last1=v[0].first;
        for (int i=1;i<v.size();++i)
        if (v[i].second!='P') {
            mx1=max(mx1,v[i].first-last1);
            last1=v[i].first;
        }
        mx1=max(mx1,v.back().first-last1);
        ans-=mx1;
        return;
    }
    long long cur2=0;
    cur2+=v.back().first-v[0].first;
    cur2+=v.back().first-v[0].first;
    cur2+=v.back().first-v[0].first;
    long long mx1=0,mx2=0;
    long long last1=v[0].first;
    long long last2=v[0].first;
    for (int i=1;i<v.size();++i) {
        if (v[i].second=='R') {
            mx1=max(mx1,v[i].first-last1);
            last1=v[i].first;
        } else {
            mx2=max(mx2,v[i].first-last2);
            last2=v[i].first;
        }
    }
    mx1=max(mx1,v.back().first-last1);
    mx2=max(mx2,v.back().first-last2);
    cur2-=mx1+mx2;
   // cout<<v[0].first<<" "<<v.back().first<<" "<<cur2<<'\n';
    if (cur2<cur) cur=cur2;
    ans+=cur;
}

int main() {
//    freopen("schedule.in","r",stdin);
  //  freopen("schedule.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>pos[i]>>c[i];
    }
    vector<pair<int,char> > v;
    for (int i=1;i<=n;++i) {
        if (c[i]=='P') {
            v.push_back(make_pair(pos[i],c[i]));
            solve(v);
            v.clear();
            v.push_back(make_pair(pos[i],c[i]));
            continue;
        } else {
            v.push_back(make_pair(pos[i],c[i]));
        }
    }
    solve(v);
    cout<<ans;
}