#include <bits/stdc++.h>
using namespace std;


int n,m,k,x;
char c[5];
long long dp[100];
int f[100];
int l[100];
inline void check(){
    if (n==2 && dp[1]==0 && f[1]==0 && l[1]==1) return;
    if (m==2 && dp[2]==0 && f[2]==0 && l[2]==1) return;
    for (int i=3;i<=k;++i) {
        f[i]=f[i-2];
        l[i]=l[i-1];
        dp[i]=dp[i-1]+dp[i-2]+(l[i-2]==0 && f[i-1]==1 ? 1 : 0);
        if (dp[i]>x) break;
    }
    if (dp[k]!=x) return;
    string s="";
    for (int i=1;i<=n;++i)
        s+="B";
    s[0]=c[f[1]];
    s[n-1]=c[l[1]];
    if ((n-2)/2>=dp[1]) {
        int last=3;
        while (dp[1]) {
            s[last-2]='A';
            s[last-1]='C';
            last+=2;
            --dp[1];
        }
    } else if (f[1]==0 && (n-3)/2+1>=dp[1]) {
        s[1]='C';
        --dp[1];
        int last=4;
        while (dp[1]) {
            s[last-2]='A';
            s[last-1]='C';
            last+=2;
            --dp[1];
        }
    } else if (l[1]==1 && (n-3)/2+1>=dp[1]) {
        s[n-2]='A';
        --dp[1];
        int last=3;
        while (dp[1]) {
            s[last-2]='A';
            s[last-1]='C';
            last+=2;
            --dp[1];
        }
    } else {
        s[1]='C';
        s[n-2]='A';
        int last=4;
        dp[1]-=2;
        while (dp[1]) {
            s[last-2]='A';
            s[last-1]='C';
            last+=2;
            --dp[1];
        }
    }
    cout<<s<<'\n';
    dp[1]=dp[2];
    n=m;
    f[1]=f[2];
    l[1]=l[2];
    s="";
    for (int i=1;i<=n;++i)
        s+="B";
    s[0]=c[f[1]];
    s[n-1]=c[l[1]];
    if ((n-2)/2>=dp[1]) {
        int last=3;
        while (dp[1]) {
            s[last-2]='A';
            s[last-1]='C';
            last+=2;
            --dp[1];
        }
    } else if (f[1]==0 && (n-3)/2+1>=dp[1]) {
        s[1]='C';
        --dp[1];
        int last=4;
        while (dp[1]) {
            s[last-2]='A';
            s[last-1]='C';
            last+=2;
            --dp[1];
        }
    } else if (l[1]==1 && (n-3)/2+1>=dp[1]) {
        s[n-2]='A';
        --dp[1];
        int last=3;
        while (dp[1]) {
            s[last-2]='A';
            s[last-1]='C';
            last+=2;
            --dp[1];
        }
    } else {
        s[1]='C';
        s[n-2]='A';
        int last=4;
        dp[1]-=2;
        while (dp[1]) {
            s[last-2]='A';
            s[last-1]='C';
            last+=2;
            --dp[1];
        }
    }
    cout<<s<<'\n';
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>x>>n>>m;
    c[0]='A';
    c[1]='C';
    c[2]='B';
    for (int i=0;i<=2;++i)
        for (int j=0;j<=2;++j)
    for (int k=0;k<=n/2;++k) if ((n==1 && k==0 && i==j) || (n==2 && i==0 && j==1 && k==1) || ((n-2)/2>=k && n-2>=0) || ((i==0 || j==1) && n-3>=0 && (n-3)/2+1>=k) || (i==0 && j==1 && n-4>=0 && (n-4)/2+2>=k)) {
        for (int ii=0;ii<=2;++ii)
            for (int jj=0;jj<=2;++jj)
        for (int kk=0;kk<=m/2;++kk) if ((m==1 && kk==0 && ii==jj) || (m==2 && ii==0 && jj==1 && kk==1) || (m-2>=0 && (m-2)/2>=kk) || ((ii==0 || jj==1) && m-3>=0 && (m-3)/2+1>=kk) || (!ii && jj==1 && m-4>=0 && (m-4)/2+2>=kk)) {
            f[1]=i;
            l[1]=j;
            f[2]=ii;
            l[2]=jj;
            dp[1]=k;
            dp[2]=kk;
            check();
        }
    }
    cout<<"Happy new year!";
}