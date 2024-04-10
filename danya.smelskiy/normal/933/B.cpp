#include <bits/stdc++.h>
using namespace std;

long long n,k;
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    long long last=n;
    while (true) {
        if (v.size()>1e6) {
            cout<<"-1";
            return 0;
        }
        if (last>=0 && last<k) {
            v.push_back(last);
            break;
        }
        long long nw;
        long long kol;
        if (last>=k) kol=-(last/k);
        else kol=(abs(last)+k-1ll)/k;
        last+=kol*k;
        if (last<0 || last>k) {
            cout<<"-1";
            return 0;
        }
        v.push_back(last);
        last=kol;
    }
//    reverse(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}