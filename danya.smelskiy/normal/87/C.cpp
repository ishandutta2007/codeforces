#include <bits/stdc++.h>
using namespace std;
int n;
int pos[500005];
int s[500005];
int last[500005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    pos[1]=1e9;
    for (int i=2;i<=n;++i) {
        pos[i]=1e9;
        for (int j=2;(j)*(j+1)/2<=i && j<=i;++j) {
            int l=i-(j*(j+1))/2;
            if (l%j==0) {
                l/=j;
                int res=s[l+j]^s[l];
                if (res==0) {
                    pos[n]=min(pos[n],j);
                }
                last[res]=i;
            }
        }
        for (int j=0;;++j)
        if (last[j]!=i) {
            s[i]=s[i-1]^j;
            break;
        }
    }
    if (pos[n]!=1e9) cout<<pos[n];
    else cout<<"-1";
}