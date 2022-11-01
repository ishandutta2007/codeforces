#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[1005];
char t[1005];
int pre[1005];
int suf[1005];
vector<vector<int> > op;
vector<int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    n=strlen(s+1);
    while(true){
        pre[0]=suf[n+1]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+(s[i]=='(');
        }
        for(int i=n;i>=1;i--){
            suf[i]=suf[i+1]+(s[i]==')');
        }
        int mx=0,pos=-1;
        for(int i=1;i<n;i++){
            if(min(pre[i],suf[i+1])>mx){
                mx=min(pre[i],suf[i+1]);
                pos=i;
            }
        }
        if(pos==-1)break;cerr<<pos<<endl;
        op.push_back(v);
        m=0;
        for(int i=1;i<=n;i++){
            if(i<=pos){
                if(s[i]==')'||pre[i]>mx)s[++m]=')';
                else op.back().push_back(i);
            }else{
                if(s[i]=='('||suf[i]>mx)s[++m]='(';
                else op.back().push_back(i);
            }
        }
        n=m;
    }
    cout<<op.size()<<endl;
    for(int i=0;i<op.size();i++){
        cout<<op[i].size()<<endl;
        for(int j=0;j<op[i].size();j++){
            cout<<op[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}