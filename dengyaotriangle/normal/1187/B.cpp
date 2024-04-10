#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const int dic=26;//lmyakioi!

int pfx[maxn][dic];
int vl[dic];
int n,m;
char x[maxn],c[maxn];
int l;

bool chk(int p){
    for(int i=0;i<dic;i++){
        if(vl[i]>pfx[p][i]) return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>(x+1)>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<dic;j++){
            pfx[i][j]=pfx[i-1][j];
        }
        pfx[i][x[i]-'a']++;
    }  
    for(int i=1;i<=m;i++){
        cin>>(c+1);
        l=strlen(c+1);
        memset(vl,0,sizeof(vl));
        for(int j=1;j<=l;j++) vl[c[j]-'a']++;
        int l=1,r=n;
        while(r-l>3){
            int m=(l+r)>>1;
            if(chk(m)){
                r=m;
            }else l=m;
        }
        for(int i=l;i<=r;i++){
            if(chk(i)){
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}