#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n,m;
string s;
long long all,dp[30];
int last[30];

inline void update(int x,int y){
    long long z=all-dp[x]+1;
    if (z<0) z+=md;
    dp[x]=(dp[x]+z)%md;
    all=(all+z)%md;
    last[x]=y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for (int i=1;i<=s.size();++i) {
        int x=s[i-1]-'a';
        update(x,i);
    }
    for (int i=1;i<=n;++i) {
        int p=-1,r=1e9;
        for (int j=0;j<m;++j){
            if (last[j]<r) {
                r=last[j];
                p=j;
            }
        }
        update(p,(int)s.size()+i);
    }
    cout<<(all+1)%md;
}