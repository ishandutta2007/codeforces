#include <bits/stdc++.h>
using namespace std;

string s,ss;
int kol[100];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    for (int i=0;i<s.size();++i) {
        ++kol[s[i]-'0'];
    }
    int len;
    int last=10;
    int ll=1;
    for (len=1;;++len) {
        if (len==last) {
            ++ll;
            last*=10;
        }
        if (s.size()==ll+len) break;
    }
    int all=s.size();
    while (len) {
        --all;
        --kol[len%10];
        len/=10;
    }
    for (int i=0;i<ss.size();++i) {
        --kol[ss[i]-'0'];
        --all;
    }
    if (all==0) {
        cout<<ss;
        return 0;
    }
    int f=0;
    for (int i=1;i<=9;++i)
    if (kol[i]) {
        f=i;
        break;
    }
    if (!f) {
        cout<<ss;
        while (kol[0]--) cout<<"0";
        return 0;
    }
    if (ss[0]=='0') {
        cout<<char(f+'0');
        --kol[f];
        while (kol[0]--) cout<<"0";
        cout<<ss;
        f=0;
        while (true) {
            while (f<=9 && kol[f]<=0) ++f;
            if (f==10) break;
            cout<<char(f+'0');
            --kol[f];
        }
        return 0;
    }
    if (f>ss[0]-'0') {
        cout<<ss;
        f=0;
        while (true) {
            while (f<=9 && kol[f]<=0) ++f;
            if (f==10) break;
            cout<<char(f+'0');
            --kol[f];
        }
        return 0;
    }
    if (f<ss[0]-'0') {
        cout<<char(f+'0');
        --kol[f];
        f=0;
        while (true) {
            while (f<ss[0]-'0' && kol[f]<=0) ++f;
            if (f>=ss[0]-'0') break;
            cout<<char(f+'0');
            --kol[f];
        }
        if (kol[ss[0]-'0']<=0 || f>ss[0]-'0') {
            cout<<ss;
            while (true) {
                while (f<=9 && kol[f]<=0) ++f;
                if (f==10) break;
                cout<<char(f+'0');
                --kol[f];
            }
            return 0;
        }
        int nxt=ss[0]-'0';
        for (int i=0;i<ss.size();++i)
        if (ss[i]-'0'!=nxt) {
            nxt=ss[i]-'0';
            break;
        }
        if (nxt>=ss[0]-'0') while (kol[ss[0]-'0']) { --kol[ss[0]-'0']; cout<<ss[0];}
        cout<<ss;
        f=0;
        while (true) {
            while (f<=9 && kol[f]<=0) ++f;
            if (f==10) break;
            cout<<char(f+'0');
            --kol[f];
        }
        return 0;
    }
    string ans=ss;
    for (int i=0;i<=9;++i)
        for (int j=1;j<=kol[i];++j)
            ans+=char(i+'0');
    string ans2="";
    ans2+=ss[0];
    --kol[ss[0]-'0'];
    while (kol[0]>0) {
        --kol[0];
        ans2+="0";
    }
    int nxt=ss[0]-'0';
    for (int i=0;i<ss.size();++i){
        if (ss[i]-'0'!=nxt) {
            nxt=ss[i]-'0';
            break;
        }
    }
    if (nxt>=ss[0]-'0') while (kol[ss[0]-'0']>0) {
        --kol[ss[0]-'0'];
        ans2+=ss[0];
    }
    ans2+=ss;
    for (int i=0;i<=9;++i)
        for (int j=1;j<=kol[i];++j)
        ans2+=char(i+'0');
    cout<<min(ans2,ans);
}