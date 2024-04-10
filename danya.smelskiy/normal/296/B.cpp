#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n;
string s,ss;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s>>ss;
    long long res=1;
    for (int i=0;i<n;++i) {
        if (s[i]=='?' && ss[i]=='?') {
            res=(res*(long long)55)%md;
        } else if (s[i]=='?') {
            res=(res*(long long)(ss[i]-'0'+1))%md;
        } else if (ss[i]=='?') {
            res=(res*(long long)(9-(s[i]-'0')+1))%md;
        } else {
            if (s[i]>ss[i]) {
                res=0;
                break;
            }
        }
    }
    long long ans=1;
    for (int i=1;i<=n;++i){
        if (s[i-1]=='?') ans=(ans*10)%md;
        if (ss[i-1]=='?') ans=(ans*10)%md;
    }
    ans=(ans+md-res)%md;
    swap(s,ss);
    res=1;
    for (int i=0;i<n;++i) {
        if (s[i]=='?' && ss[i]=='?') {
            res=(res*(long long)55)%md;
            continue;
        } else if (s[i]=='?') {
            res=(res*(long long)(ss[i]-'0'+1))%md;
        } else if (ss[i]=='?') {
            res=(res*(long long)(9-(s[i]-'0')+1))%md;
        } else {
            if (s[i]>ss[i]) {
                res=0;
                break;
            }
        }
    }
    ans=(ans+md-res)%md;
    res=1;
    for (int i=0;i<n;++i) {
        if (s[i]=='?' && ss[i]=='?') res=(res*10)%md;
        else if (s[i]=='?' || ss[i]=='?') {} else if (s[i]!=ss[i]) {
            res=0;
            break;
        }
    }
    ans=(ans+md+res)%md;
    cout<<ans;
}