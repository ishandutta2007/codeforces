#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

ll sti(string s){
    ll res=0;
    for(int i=0;i<s.size();i++){
        res*=10;
        res+=(s[i]-'0');
    }
    return res;
}

int n;
string a[100005];
ll ext[100005][11];
ll ans;
int cnt[11];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(ext,-1,sizeof(ext));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        string s=a[i];
        cnt[s.size()]++;
        int cc=0;
        ext[i][cc]=sti(s)%mod;
        for(int j=s.size()-1;j>=0;j--){
            cc++;
            char c='0';
            s=s.substr(0,j)+'0'+s.substr(j,s.size()-j);
            ext[i][cc]=sti(s)%mod;
        }
        for(int j=1;j<=10;j++){
            if(ext[i][j]==-1)ext[i][j]=ext[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            ans+=ext[i][j-1]*10*cnt[j];
            ans%=mod;
            ans+=ext[i][j]*cnt[j];
            ans%=mod;
        }
    }
    cout<<ans<<endl;

    return 0;
}