#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;

string s;
bitset<MAXN> q[26];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=0;i<s.size();++i) q[s[i]-'a'][i]=1;
    int m;
    cin>>m;
    int tp;
    string ss;
    char c;
    int l,r;
    int x;
    int res;
    while (m--) {
        cin>>tp;
        if (tp==1) {
            cin>>x; --x;
            cin>>c;
            q[(s[x]-'a')][x]=0;
            s[x]=c;
            q[(c-'a')][x]=1;
            continue;
        }
        cin>>l>>r>>ss;
        --l; --r;
        r=r-(int)ss.size()+1;
        if (l>r) {
            cout<<0<<'\n';
            continue;
        }
        bitset<MAXN> z;
        z.set();
        for (int j=0;j<ss.size();++j) {
            x=(ss[j]-'a');
            z=(z&(q[x]>>j));
        }
        res=(z>>l).count();
        res-=(z>>(r+1)).count();
        cout<<res<<'\n';
    }
}