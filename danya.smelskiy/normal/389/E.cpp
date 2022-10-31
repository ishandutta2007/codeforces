#include <bits/stdc++.h>
using namespace std;



long long s1,s2;
int n,m;
int x;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    vector<int> v;
    for (int i=1;i<=n;++i) {
        cin>>m;
        for (int j=1;j<=m;++j) {
            cin>>x;
            if ((m&1) && j==(m+1)/2) v.push_back(x);
            else if (j<=m/2) s1+=x;
            else s2+=x;
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (int i=0;i<v.size();++i)
        if (i&1) s2+=v[i];
        else s1+=v[i];
    cout<<s1<<" "<<s2<<'\n';
}