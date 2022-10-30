#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > ans;
bool prime[100005];
bool used[100005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=2;i<=sqrt(n);++i) if (prime[i]==false) {
        for (int j=i*i;j<=n;j+=i)
            prime[j]=true;
    }
    for (int i=3;i<=n/2;++i) if (prime[i]==false){
        vector<int> v;
        for (int j=i;j<=n;j+=i)
            if (used[j]==false) v.push_back(j);
        int sz=v.size();
        if (sz==1) continue;
        if (sz&1) {
            vector<int> vv;
            for (int j=0;j<v.size();++j)
                if (v[j]!=i+i) vv.push_back(v[j]);
            v=vv;
        }
        for (int j=1;j<v.size();j+=2) {
            ans.push_back(make_pair(v[j-1],v[j]));
            used[v[j]]=used[v[j-1]]=true;
        }
    }
    vector<int> v;
    for (int i=2;i<=n;i+=2)
        if (used[i]==false) v.push_back(i);
    for (int i=1;i<v.size();i+=2)
        ans.push_back(make_pair(v[i-1],v[i]));
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}