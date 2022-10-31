#include <bits/stdc++.h>
using namespace std;



int n;
int a[105];
int x;
vector<int> v;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        x=a[i];
        vector<int> vv;
        sort(v.begin(),v.end());
        bool t=false;
        for (int j=v.size()-1;j>=0;--j) {
            if (v[j]<=x) {
                t=true;
                vv.push_back(v[j]+1);
                x=-1;
            } else vv.push_back(v[j]);
        }
        if (!t) vv.push_back(1);
        v=vv;
    }
    cout<<v.size();
}