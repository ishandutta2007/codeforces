#include <bits/stdc++.h>
using namespace std;




inline string bt(long long x) {
    if (x==0) return "0";
    string res="";
    while (x) {
        res+=char('0'+x%2ll);
        x/=2ll;
    }
    reverse(res.begin(),res.end());
    return res;
}

inline long long f(string s){
    long long res=0;
    reverse(s.begin(),s.end());
    for (int i=0;i<s.size();++i)
        if (s[i]=='1') res+=(1ll<<i);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    while (n--) {
        long long l,r;
        cin>>l>>r;
        string ll=bt(l);
        string rr=bt(r);
        bool t=false;
        for (int i=0;i<rr.size();++i)
        if (rr[i]=='0') {
            t=true;
            break;
        }
        if (t==false) {
            cout<<r<<'\n';
            continue;
        }
        string res="";
        if (ll.size()<rr.size()) {
            for (int i=1;i<rr.size();++i)
                res+="1";
        } else {
            for (int i=0;i<rr.size();++i)
                if (ll[i]==rr[i]) res+=rr[i];
                else {
                    bool tt=false;
                    for (int j=i+1;j<rr.size();++j)
                    if (rr[j]=='0') {
                        tt=true;
                        break;
                    }
                    if (tt==false) {
                        res=rr;
                        break;
                    }
                    res+="0";
                    for (int j=i+1;j<rr.size();++j)
                        res+="1";
                    break;
                }
        }
        cout<<f(res)<<'\n';
    }
}