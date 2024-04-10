#include <bits/stdc++.h>
using namespace std;

string s;
int n,ans;
string ss[200];
int pos;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>ss[i];
    int l=0;
    for (int i=1;i<=s.size();++i) {
        for (int j=1;j<=n;++j) if (ss[j].size()<=i){
            int r1=i;
            int r2=ss[j].size();
            bool t=false;
            while (r1 && r2) {
                if (s[r1-1]!=ss[j][r2-1]) {
                    t=true;
                    break;
                }
                --r1; --r2;
            }
            if (t==false) {
                int rr=i-(int)ss[j].size()+1;
                l=max(l,rr);
            }
        }
        if (i-l>ans){
            ans=i-l;
            pos=l;
        }
    }
    cout<<ans<<" "<<pos;
}