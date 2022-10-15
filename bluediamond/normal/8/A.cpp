#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int len=s.size();
    string a;
    cin>>a;
    int n=a.size();
    string b;
    cin>>b;
    int m=b.size();
    bool e1=0,e2=0;
    /// 1 :
    int gata=len;
    for(int i=0;i<len;i++) {
        bool is=1;
        for(int j=0;j<n;j++) {
            if(i+j>=len){is=0;break;}
            if(a[j]!=s[i+j]) {
                is=0;
                break;
            }
        }
        if(is==1) {
            gata=i+n-1;
            break;
        }
    }
    for(int i=gata+1;i<len;i++) {
        bool is=1;
        for(int j=0;j<m;j++) {
            if(i+j>=len){is=0;break;}
            if(b[j]!=s[i+j]) {
                is=0;
                break;
            }
        }
        if(is==1) {
            e1=1;
            break;
        }
    }

    /// 2 :
    reverse(s.begin(),s.end());
    gata=len;
    for(int i=0;i<len;i++) {
        bool is=1;
        for(int j=0;j<n;j++) {
            if(i+j>=len){is=0;break;}
            if(a[j]!=s[i+j]) {
                is=0;
                break;
            }
        }
        if(is==1) {
            gata=i+n-1;
            break;
        }
    }
    for(int i=gata+1;i<len;i++) {
        bool is=1;
        for(int j=0;j<m;j++) {
            if(i+j>=len){is=0;break;}
            if(b[j]!=s[i+j]) {
                is=0;
                break;
            }
        }
        if(is==1) {
            e2=1;
            break;
        }
    }
    if(e1==1 && e2==0)
        cout<<"forward\n";
    if(e1==0 && e2==1)
        cout<<"backward\n";
    if(e1==1 && e2==1)
        cout<<"both\n";
    if(e1==0 && e2==0)
        cout<<"fantasy\n";
    return 0;
}
/**


**/