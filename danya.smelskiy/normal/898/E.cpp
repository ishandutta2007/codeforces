#include <bits/stdc++.h>
using namespace std;



int n;
int a[200005];
vector<int> v1,v2;

inline bool f(int x) {
    int y=sqrt(x);
    return (y*y==x);
}

inline int get1(int x) {
    int y=x;
    int cnt=0;
    int res=1e9;
    while (true) {
        if (f(y)) {
            ++y;
            ++cnt;
        } else break;
    }
    y=x;
    res=cnt;
    cnt=0;
    while (true) {
        if (f(y)) {
            --y;
            ++cnt;
            if (y<0) break;
        } else break;
    }
    if (y>=0) res=min(res,cnt);
    return res;
}

inline int get2(int x) {
    int y=sqrt(x);
    int res=2e9;
    int z=y*y;
    res=min(res,abs(x-z));
    z=(y+1)*(y+1);
    res=min(res,abs(x-z));
    --y;
    if (y>=0) {
        z=y*y;
        res=min(res,abs(x-z));
    }
    return res;
}


int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (f(a[i])) v1.push_back(get1(a[i]));
        else v2.push_back(get2(a[i]));
    }
    if (v1.size()==v2.size()) {
        cout<<"0";
        return 0;
    }
    long long ans=0;
    if (v1.size()>n/2) {
        sort(v1.begin(),v1.end());
        for (int i=0;i<v1.size()-n/2;++i)
            ans+=v1[i];
        cout<<ans;
        return 0;
    }
    sort(v2.begin(),v2.end());
    for (int i=0;i<v2.size()-n/2;++i)
        ans+=v2[i];
    cout<<ans;
}