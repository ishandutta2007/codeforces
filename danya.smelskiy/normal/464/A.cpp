#include <bits/stdc++.h>
using namespace std;
long long n,m;
string ans;
bool t;
string s;
int main(){
    cin>>n>>m>>s;
    for (int i=n;i>=1;--i){
        for (int j=s[i-1]+1;j<='a'+m-1;++j){
            if ((j!=s[i-2]) && j!=s[i-3]){
                int last=i;
                string ss=s;
                ss[i-1]=char(j);
                for (int k=i+1;k<=ss.size();++k)
                for (int z=1;z<=m;++z){
                    if (char('a'+z-1)!=ss[k-2] && char('a'+z-1)!=ss[k-3]){
                        last=k;
                        ss[k-1]=char('a'+z-1);
                        break;
                    }
                }
                if (last==n){
                    if (t==false){
                        t=true;
                        ans=ss;
                    } else ans=min(ans,ss);
                }
            }
        }
    }
    if (t==true) cout<<ans;
    else
    cout<<"NO";
}