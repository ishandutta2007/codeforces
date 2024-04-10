#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

string s,ss;
int n;
long long ans[100],p[100];
vector<int> v[100005];
int q[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>n;
    for (int i=0;i<=9;++i)
        p[i]=10,ans[i]=i;
    for (int i=1;i<=n;++i) {
        cin>>ss;
        q[i]=ss[0]-'0';
        for (int j=3;j<ss.size();++j)
            v[i].push_back(ss[j]-'0');
    }
    for (int i=n;i>0;--i) {
        long long pw=1;
        long long res=0;
        for (int j=0;j<v[i].size();++j) {
            int to=v[i][j];
            res=(res*p[to])%md;
            res=(res+ans[to])%md;
            pw=(pw*p[to])%md;
        }
        ans[q[i]]=res;
        p[q[i]]=pw;
    }
    long long res=0;
    for (int i=0;i<s.size();++i) {
        int x=s[i]-'0';
        res=(res*p[x])%md;
        res=(res+ans[x])%md;
    }
    cout<<res;
}