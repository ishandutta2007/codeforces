#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool used[100];
int dp[(1<<24)+10];

long long ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        string ss="";
        for (int j=0;j<s.size();++j)
        if (used[s[j]-'a']==false) {
            used[s[j]-'a']=true;
            ss+=s[j];
        }
        for (int j=0;j<ss.size();++j)
            used[ss[j]-'a']=false;
        for (int j=0;j<(1<<(ss.size()));++j){
            int mask=0;
            int kol=0;
            for (int k=0;k<ss.size();++k)
                if (j&(1<<k)) {
                    ++kol;
                    int y=ss[k]-'a';
                    mask=mask|(1<<y);
                }
            if (kol==0) continue;
            if (kol%2==1) dp[mask]++;
            else dp[mask]--;
        }
    }
    //
    for (int i=1;i<=24;++i) {
        for (int j=0;j<(1<<24);++j)
        if (j&(1<<(i-1))) {
            dp[j]+=dp[j^(1<<(i-1))];
        }
    }
    for (int j=0;j<(1<<24);++j){
        ans=ans^(dp[j]*dp[j]);
    }
    cout<<ans;
}