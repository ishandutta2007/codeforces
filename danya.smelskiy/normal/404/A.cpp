#include <bits/stdc++.h>
using namespace std;
char startx,starty;
bool t;
string s;
int n;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        if (i==1) startx=s[0];
        if (i==1) starty=s[1];
        for (int j=1;j<=n;++j){
            if (i==j || i==n-j+1){
                if (s[j-1]!=startx) t=true;
            } else if (starty!=s[j-1]) t=true;
        }
    }
    if ((startx==starty && n!=1) || t==true) cout<<"NO";
    else cout<<"YES";

}