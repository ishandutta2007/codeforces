#include <bits/stdc++.h>
using namespace std;
int mod[2]={998244353, 897581057};

int po(int x, int y, int mod)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}

void ntt(int *A, int n, int w, int mod)
{
    int stw[n];
    stw[0]=1;
    for(int a=1; a<n; a++) stw[a]=(1ll*w*stw[a-1])%mod;
    for(int a=0, b=0; a<n; a++)
    {
        if(a<b) swap(A[a], A[b]);
        int i=(n>>1);
        while(b&i)
        {
            b-=i, i>>=1;
        }
        b+=i;
    }
    int cs=n;
    for(int i=1; i<n; i<<=1)
    {
        cs>>=1;
        for(int a=0; a<n; a+=(i<<1))
        {
            int st=0;
            for(int b=a; b<a+i; b++)
            {
                int x=A[b], y=(1ll*stw[st]*A[b+i])%mod;
                A[b]=x+y;
                if(A[b]>=mod) A[b]-=mod;
                A[b+i]=x-y;
                if(A[b+i]<0) A[b+i]+=mod;
                st+=cs;
            }
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int p[26];
    for(int a=0; a<26; a++) cin>>p[a], p[a]--;
    string s, t;
    cin>>t>>s;
    int an[s.size()-t.size()+1];
    for(int a=0; a<=s.size()-t.size(); a++) an[a]=1;
    for(int i=0; i<2; i++)
    {
        int n=1;
        while(n<s.size()+t.size()) n<<=1;
        int A[3][n], B[3][n], w=po(3, (mod[i]-1)/n, mod[i]);
        for(int j=0; j<n; j++)
        {
            for(int a=0; a<3; a++) A[a][j]=0, B[a][j]=0;
        }
        int su=0;
        for(int j=0; j<t.size(); j++)
        {
            int a=t[t.size()-1-j]-'a', b=p[a];

            A[0][j]=(mod[i]-2*a*b*(a+b))%mod[i];
            A[1][j]=a*a+b*b+4*a*b;
            A[2][j]=(mod[i]-2*(a+b))%mod[i];

            su=(su+a*a*b*b)%mod[i];
        }
        for(int j=0; j<3; j++) ntt(A[j], n, w, mod[i]);

        int pref[s.size()+1];
        pref[0]=0;
        for(int j=0; j<s.size(); j++)
        {
            int c=s[j]-'a';
            B[0][j]=c;
            B[1][j]=c*c;
            B[2][j]=c*c*c;
            pref[j+1]=(pref[j]+c*c*c*c)%mod[i];
        }
        for(int j=0; j<3; j++) ntt(B[j], n, w, mod[i]);

        for(int j=0; j<n; j++)
        {
            for(int a=0; a<3; a++) A[a][j]=(1ll*A[a][j]*B[a][j])%mod[i];
        }
        for(int j=0; j<3; j++) ntt(A[j], n, po(w, mod[i]-2, mod[i]), mod[i]);

        int rn=po(n, mod[i]-2, mod[i]);
        for(int j=0; j+t.size()<=s.size(); j++)
        {
            int st=t.size()-1+j, x=(0ll+mod[i]+pref[j+t.size()]-pref[j]+su)%mod[i];
            for(int a=0; a<3; a++)
            {
                x=(x+1ll*A[a][st]*rn)%mod[i];
            }
            if(x) an[j]=0;
        }
    }
    for(int a=0; a<=s.size()-t.size(); a++) cout<<an[a];
}