#include <bits/stdc++.h>
using namespace std;

int n;
int x;
long long ans;
multiset<int> s;
long long a[6];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        s.insert(x);
    }
    while (s.size()>=4) {
        multiset<int>  :: iterator  q;
        q=s.end();
        --q;
        a[1]=*q; --q; a[2]=*q; --q; a[3]=*q; --q; a[4]=*q;
        swap(a[1],a[4]);
        swap(a[2],a[3]);
        if (a[3]>=a[4]-1) {
            if (a[1]>=a[2]-1) {
                ans+=a[1]*a[3];
                for (int j=1;j<=4;++j)
                    s.erase(s.find(a[j]));
                } else {
                    s.erase(s.find(a[2]));
                }
        } else {
            s.erase(s.find(a[4]));
        }
    }
    cout<<ans;
}