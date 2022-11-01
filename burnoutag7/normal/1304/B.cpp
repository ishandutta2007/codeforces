#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
string s[105],rs[105],res,cen;
bool u[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
        rs[i]=s[i];
        reverse(rs[i].begin(),rs[i].end());
        for(int j=0;j<i;j++){
            if(!u[j]&&s[j]==rs[i]){
                u[i]=u[j]=1;
                ans+=2;
                res+=s[j];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!u[i]&&s[i]==rs[i]){
            ans++;
            cen=s[i];
            break;
        }
    }
    string tmp=res;
    reverse(tmp.begin(),tmp.end());
    res=res+cen+tmp;
    cout<<ans*m<<endl<<res<<endl;

    return 0;
}