#include<bits/stdc++.h>
using namespace std;

int n,m,ti,td,tr,te,f[5005][5005],ps[5005][26],pt[5005][26];
char s[5005],t[5005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>ti>>td>>tr>>te;
    tr=min(ti+td,tr);
    cin>>s+1>>t+1;
    n=strlen(s+1);
    m=strlen(t+1);
    for(int i=1;i<=n;i++){
        memcpy(ps[i],ps[i-1],sizeof(ps[0]));
        ps[i][s[i]-'a']=i;
    }
    for(int i=1;i<=m;i++){
        memcpy(pt[i],pt[i-1],sizeof(pt[0]));
        pt[i][t[i]-'a']=i;
    }
    for(int i=1;i<=n;i++)f[i][0]=i*td;
    for(int i=1;i<=m;i++)f[0][i]=i*ti;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=f[i-1][j-1]+(s[i]==t[j]?0:tr);
            f[i][j]=min(f[i][j],f[i-1][j]+td);
            f[i][j]=min(f[i][j],f[i][j-1]+ti);
            int cps=ps[i-1][t[j]-'a'],cpt=pt[j-1][s[i]-'a'];
            if(cps&&cpt)f[i][j]=min(f[i][j],f[cps-1][cpt-1]+te+(i-cps-1)*td+(j-cpt-1)*ti);
        }
    }
    cout<<f[n][m];

    return 0;
}