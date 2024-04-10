#include<bits/stdc++.h>
using namespace std;

int n,m,f[205][205][405];
char s[205],t[205],fa[205][205][405];

void upd(int i,int j,int k,int v,char c){
    if(v<f[i][j][k]){
        f[i][j][k]=v;
        fa[i][j][k]=c;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1>>t+1;
    n=strlen(s+1);
    m=strlen(t+1);
    memset(f,0x3f,sizeof(f));
    f[0][0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=1;k<=400;k++){
                upd(i,j,k,f[i-(s[i]=='(')][j-(t[j]=='(')][k-1]+1,'(');
            }
            for(int k=399;k>=0;k--){
                upd(i,j,k,f[i-(s[i]==')')][j-(t[j]==')')][k+1]+1,')');
            }
        }
    }
    int x=n,y=m,z=0;
    string ans;
    while(x||y||z){
        ans+=fa[x][y][z];
        if(fa[x][y][z]=='('){
            x-=s[x]=='(';
            y-=t[y]=='(';
            z--;
        }else{
            x-=s[x]==')';
            y-=t[y]==')';
            z++;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;

    return 0;
}