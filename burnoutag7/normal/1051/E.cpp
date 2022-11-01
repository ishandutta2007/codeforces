#include<bits/stdc++.h>
using namespace std;

void z_algorithm(char *s,int *z,int n){
    memset(z,0,n<<2);
    int c=0;
    for(int i=1;i<n;i++){
        if(i+z[i-c]<c+z[c]){
            z[i]=z[i-c];
        }else{
            z[i]=max(0,c+z[c]-i);
            while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
            c=i;
        }
    }
    z[0]=n;
}

const int mod=998244353;

char a[1000005],l[1000005],r[1000005],s[2000005];
int lena,lenl,lenr,z[2000005],sl[1000005],sr[1000005],f[1000005],g[1000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>l>>r;
    lena=strlen(a);
    lenl=strlen(l);
    lenr=strlen(r);
    memcpy(s,l,lenl);
    s[lenl]='#';
    memcpy(s+lenl+1,a,lena);
    z_algorithm(s,z,lenl+1+lena);
    for(int i=0;i<lena;i++)sl[i]=z[lenl+1+i];
    memcpy(s,r,lenr);
    s[lenr]='#';
    memcpy(s+lenr+1,a,lena);
    z_algorithm(s,z,lenr+1+lena);
    for(int i=0;i<lena;i++)sr[i]=z[lenr+1+i];
    f[lena]=g[lena]=1;
    for(int i=lena-1;i>=0;i--){
        int pl=i+lenl,pr=i+lenr;
        pl+=sl[i]<lenl&&a[i+sl[i]]<l[sl[i]];
        pr-=sr[i]<lenr&&a[i+sr[i]]>r[sr[i]];
        pr=min(pr,lena);
        if(a[i]=='0')pr=i+1;
        if(pl<=pr){
            f[i]=(g[pl]-g[pr+1]+mod)%mod;
        }
        g[i]=(f[i]+g[i+1])%mod;
    }
    cout<<f[0];

    return 0;
}