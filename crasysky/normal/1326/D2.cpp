#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pb push_back
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define sit set<int>::iterator
using namespace std;
const int N=1e6+6,b1=27,P1=1e9+7,b2=1003,P2=998244353;
int a[N],b[N],Ha1[N],Ha2[N],Hb1[N],Hb2[N],pw1[N],pw2[N];
char s[N];
bool check(int l1,int r1,int l2,int r2){
    int sa1=(Ha1[r1]-(ll)Ha1[l1-1]*pw1[r1-l1+1]%P1+P1)%P1;
    int sa2=(Ha2[r1]-(ll)Ha2[l1-1]*pw2[r1-l1+1]%P2+P2)%P2;
    int sb1=(Hb1[r2]-(ll)Hb1[l2-1]*pw1[r2-l2+1]%P1+P1)%P1;
    int sb2=(Hb2[r2]-(ll)Hb2[l2-1]*pw2[r2-l2+1]%P2+P2)%P2;
    return sa1==sb1&&sa2==sb2;
}
int read(){
    int c=0,f=1; char ch=getchar();
    while ((ch<'0'||'9'<ch)&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c*f;
}
int main(){
    int T=read();
    while (T--){
        cin>>s;
        int n=strlen(s);
        for (int i=1;i<=n;++i) a[i]=s[i-1]-'a'+1;
        for (int i=1;i<=n;++i) b[i]=a[n-i+1];
        pw1[0]=pw2[0]=1;
        for (int i=1;i<=n;++i)
            pw1[i]=(ll)pw1[i-1]*b1%P1,pw2[i]=(ll)pw2[i-1]*b2%P2;
        for (int i=1;i<=n;++i){
            Ha1[i]=((ll)Ha1[i-1]*b1+a[i])%P1;
            Ha2[i]=((ll)Ha2[i-1]*b2+a[i])%P2;
            Hb1[i]=((ll)Hb1[i-1]*b1+b[i])%P1;
            Hb2[i]=((ll)Hb2[i-1]*b2+b[i])%P2;
        }
        int l=0,r=n+1;
        while (l+1<r-1&&a[l+1]==a[r-1]) ++l,--r;
        int mxl=0;
        for (int i=1;l+i<r;++i)
            if (check(l+1,l+i,n-(l+i)+1,n-(l+1)+1)) mxl=i;
        int mxr=0;
        for (int i=1;l+i<r;++i)
            if (check(r-i,r-1,n-(r-1)+1,n-(r-i)+1)) mxr=i;
        if (mxl>mxr){
            for (int i=1;i<=l+mxl;++i) printf("%c",char(a[i]+'a'-1));
            for (int i=r;i<=n;++i) printf("%c",char(a[i]+'a'-1));
            putchar('\n');
        }
        else{
            for (int i=1;i<=l;++i) printf("%c",char(a[i]+'a'-1));
            for (int i=r-mxr;i<=n;++i) printf("%c",char(a[i]+'a'-1));
            putchar('\n');
        }
    }
    return 0;
}