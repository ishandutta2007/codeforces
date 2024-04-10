#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int l[606];
int r[606];
int rr;
int pos[606];
int q[606];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>l[i]>>r[i];
        ++rr;
        q[rr]=i;
        pos[i]=s.size();
        s+="(";
        while (rr && pos[q[rr]]+l[q[rr]]<=s.size()) {
            if (pos[q[rr]]+r[q[rr]]<s.size()) {
                cout<<"IMPOSSIBLE";
                return 0;
            }
            s+=")";
            --rr;
        }
    }
    cout<< (rr ? "IMPOSSIBLE" : s);
}