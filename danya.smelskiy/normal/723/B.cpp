#include <bits/stdc++.h>
using namespace std;
int n,kolin,ans,last;
string s;
bool t;
char x;
int main(){
    cin>>n;
    cin>>s;
    for (int i=0;i<n;++i){
        x=s[i];
        if (s[i]=='('){
                if (last>ans) ans=last;
                last=0;
                t=true;
            } else
        if (s[i]==')'){
                if (last>0){
                    ++kolin;
                    last=0;
                }
                t=false;
        } else
        if (s[i]=='_'){
            if (t==true && last>0) ++kolin;
            if (t==false && last>ans) ans=last;
            last=0;
        } else ++last;
        if (last>ans && t==false) ans=last;
    }
    cout<<ans<<" "<<kolin;
}