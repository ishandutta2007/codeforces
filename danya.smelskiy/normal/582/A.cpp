#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> q;
map<int,int> kol;
int a[300005];

inline bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n*n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n*n+1,cmp);
    q.push_back(a[1]);
    if (n==1) {
        cout<<a[1];
        return 0;
    }
    q.push_back(a[2]);
    kol[__gcd(a[1],a[2])]+=2;
    for (int i=3;i<=n*n;++i) {
        if (kol[a[i]]) --kol[a[i]];
        else {
            for (int j=0;j<q.size();++j)
                kol[__gcd(q[j],a[i])]+=2;
            q.push_back(a[i]);
            if (q.size()==n) break;
        }
    }
    for (int i=0;i<q.size();++i)
        cout<<q[i]<<" ";

}