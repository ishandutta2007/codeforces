#include <bits/stdc++.h>
using namespace std;
string s;
int a[5];
int ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    int x=((s[0]-'0')*10+(s[1]-'0'));
    int y=((s[3]-'0')*10+(s[4]-'0'));
    while (true) {
        a[0]=x/10;
        a[1]=x%10;
        a[2]=y/10;
        a[3]=y%10;
        if (a[0]==a[3] && a[1]==a[2]) {
            cout<<ans;
            return 0;
        }
        ++ans;
        ++y;
        if (y==60) {
            y=0;
            ++x;
            if (x==24) x=0;
        }
    }
}