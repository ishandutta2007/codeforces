#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int kol[1000];
string ans[400005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i=0;i<n;++i){
        ++kol[s[i]];
    }
    int kolp1=0,kolnep1=0;
    for (int i='a';i<='z';++i) {
        kolp1+=kol[i]/2;
        kolnep1+=kol[i]%2;
    }
    for (int i='A';i<='Z';++i) {
        kolp1+=kol[i]/2;
        kolnep1+=kol[i]%2;
    }
    for (int i='0';i<='9';++i) {
        kolp1+=kol[i]/2;
        kolnep1+=kol[i]%2;
    }
    for (int i=1;i<=n;++i) if (n%i==0) {
        int l=n/i;
        int kolp=(i*(l/2));
        int kolnep=0;
        if (kolp>kolp1) continue;
        kolp=kolp1-kolp;
        kolp=kolp*2+kolnep1;
        if ((l&1) && kolp>i) continue;
        else if ((l&1)==0 && kolp) continue;
            cout<<i<<'\n';
            if (i==n) {
                for (int i=0;i<n;++i)
                    cout<<s[i]<<" ";
                return 0;
            }
            kolp=(i*(l/2));
            int l1=1;
            int l2=l/2;
            for (int j='a';j<='z';++j) {
                while (kol[j]>=2 && l1<=i) {
                    if (ans[l1].size()>=l2) {
                        ++l1;
                        if (l1>i) break;
                    }
                    ans[l1]+=char(j);
                    kol[j]-=2;
                }
            }
            for (int j='A';j<='Z';++j) {
                while (kol[j]>=2 && l1<=i) {
                    if (ans[l1].size()>=l2) {
                        ++l1;
                        if (l1>i) break;
                    }
                    ans[l1]+=char(j);
                    kol[j]-=2;
                }
            }
            for (int j='0';j<='9';++j) {
                while (kol[j]>=2 && l1<=i) {
                    if (ans[l1].size()>=l2) {
                        ++l1;
                        if (l1>i) break;
                    }
                    ans[l1]+=char(j);
                    kol[j]-=2;
                }
            }
            int l3;
            l1='a',l2='A',l3='0';
            for (int j=1;j<=i;++j) {
                if (!(l&1)) {
                    string res=ans[j];
                    reverse(res.begin(),res.end());
                    ans[j]+=res;
                    cout<<ans[j]<<" ";
                    continue;
                }
                string res=ans[j];
                while (l1<='z' && !kol[l1]) ++l1;
                while (l2<='Z' && !kol[l2]) ++l2;
                while (l3<='9' && !kol[l3]) ++l3;
                if (kol[l1]) {
                    --kol[l1];
                    ans[j]+=char(l1);
                } else if (kol[l2]) {
                    --kol[l2];
                    ans[j]+=char(l2);
                } else if (kol[l3]){
                    --kol[l3];
                    ans[j]+=char(l3);
                }
                reverse(res.begin(),res.end());
                ans[j]+=res;
                cout<<ans[j]<<" ";
            }
            return 0;
    }
}