#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+3;
int pkmp[MAXN];
int skmp[MAXN];
int tekmp[3*MAXN];
string solve(string s){
    int lcp=0;
    int n=sz(s);
    string og=s;
    int ans=0;
    while(lcp<n-lcp-1&&s[lcp]==s[n-lcp-1])lcp++;
    s=s.substr(lcp,n-2*lcp);
    n=sz(s);
    for(int i=1;i<n;i++){
        int j=pkmp[i-1];
        while (j > 0 && s[i] != s[j])j = pkmp[j-1];
        if (s[i] == s[j])j++;
        pkmp[i] = j;
    }
    string rs=s;
    reverse(rs.begin(),rs.end());
    string a=s+"$"+rs;
    for(int i=1;i<sz(a);i++){
        int j=tekmp[i-1];
        while (j > 0 && a[i] != a[j])j = tekmp[j-1];
        if (a[i] == a[j])j++;
        tekmp[i] = j;
    }
    for(int i=n+1;i<sz(a);i++){
        skmp[n-(i-n)]=tekmp[i];
    }
    for(int i=0;i<n;i++){
        if((i+1)*2-1<=n&&skmp[i+1]>=i){
            if((i+1)*2-1>ans){
                ans=(i+1)*2-1;
            }
        }
        if(i*2<=n&&skmp[i]>=i){
            if(i*2>ans){
                ans=i*2;
            }
        }
    }
    ans+=lcp*2;
    int half=ans/2;
    string kek=og.substr(0,half);
    string l=kek;
    reverse(l.begin(),l.end());
    string mid="";
    if(ans%2)mid=og[half];
    return kek+mid+l;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ans=solve(s);
        reverse(s.begin(),s.end());
        string ans2=solve(s);
        if(sz(ans2)>sz(ans))swap(ans,ans2);
        cout<<ans<<"\n";
    }
    return 0;
}