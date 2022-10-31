#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    if (n&1) {
        ++n;
        for (int i=1;i<=n;++i)
            if (i<=n/2) cout<<"4"; else cout<<"7";
        return 0;
    }
    int kol1=0,kol2=0;
    int pos=-1;
    char mustplace;
    for (int i=1;i<=n;++i) {
        char x=s[i-1];
        if (x=='7') {
            ++kol2;
            continue;
        }
        if (x=='4') {
            int ll=n-i;
            ll-=abs(kol1-(kol2+1));
            if (ll>=0 && ll%2==0)  { pos=i; mustplace='7';}
             ++kol1;
            continue;
        }
        int ll=n-i;
        ll-=abs(kol1+1-kol2);
        if (x<='3' && ll>=0 && ll%2==0) {
            pos=i;
            mustplace='4';
            break;
        }
        ll=n-i;
        ll-=abs(kol1-kol2-1);
        if (x<='6' && ll>=0 && ll%2==0) {
            pos=i;
            mustplace='7';
            break;
        }
        break;
    }
    if (kol1==kol2 && kol1+kol2==n) {
        cout<<s;
        return 0;
    }
    if (pos==-1) {
        n+=2;
        for (int i=1;i<=n;++i)
            if (i<=n/2) cout<<'4'; else cout<<'7';
        return 0;
    }
    s[pos-1]=mustplace;
    kol1=0;
    kol2=0;
    for (int i=1;i<=pos;++i){
        if (s[i-1]=='4') ++kol1;
        else ++kol2;
        cout<<s[i-1];
    }
    int ll=n-pos;
    ll-=abs(kol1-kol2);
    ll/=2;
    if (kol1>kol2) { kol1-=kol2; kol2=0;} else {kol2-=kol1; kol1=0;}
    swap(kol1,kol2);
    kol1+=ll; kol2+=ll;
    for (int i=pos+1;i<=n;++i){
        if (kol1>0) {
            cout<<'4';
            --kol1;
        } else {
            cout<<'7';
        }
    }
}