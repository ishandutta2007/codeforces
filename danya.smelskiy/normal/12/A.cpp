#include <bits/stdc++.h>
using namespace std;

string s[5];
int q,qq;

int main(){
    for (int i=1;i<=3;++i) {
        cin>>s[i];
    }
    for (int i=1;i<=3;++i) {
        if (i==1) q=3;
        else if (i==2) q=2;
        else q=1;
        for (int j=1;j<=3;++j) {
            if (j==1) qq=3;
            else if (j==2) qq=2;
            else qq=1;
            if (s[q][qq-1]!=s[i][j-1]) {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}