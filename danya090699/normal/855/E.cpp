//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=60;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    int val[11][11][sz];
    for(int a=2; a<=10; a++)
    {
        for(int b=0; b<=a; b++)
        {
            int dp[sz][a+1];
            for(int c=0; c<sz; c++) for(int d=0; d<=a; d++) dp[c][d]=0;
            dp[0][b]=1;
            for(int c=0; c<sz-1; c++)
            {
                for(int d=0; d<=a; d++)
                {
                    if(d!=0) dp[c+1][d-1]+=dp[c][d]*d;
                    if(d!=a) dp[c+1][d+1]+=dp[c][d]*(a-d);
                }
            }
            for(int c=0; c<sz; c++) val[a][b][c]=dp[c][0];
        }
    }
    for(int i=0; i<q; i++)
    {
        int os, lg, rg, an=0;
        scanf("%lld%lld%lld", &os, &lg, &rg);
        int l[sz], r[sz];
        for(int a=0; a<sz; a++)
        {
            l[a]=lg%os, lg/=os;
            r[a]=rg%os, rg/=os;
        }
        int di=-1, q=0;
        bool ch[os];
        for(int a=0; a<os; a++) ch[a]=0;
        int stl=0, str=0;
        for(int a=sz-1; a>=0; a--)
        {
            if(l[a]!=0) stl=1;
            if(r[a]!=0) str=1;
            if(l[a]!=r[a])
            {
                for(int b=l[a]+1; b<r[a]; b++)
                {
                    int nq=q;
                    if(ch[b]) nq--;
                    else nq++;
                    an+=val[os][nq][a];
                }
                di=a;
                break;
            }
            else if(stl==1)
            {
                if(ch[l[a]]==0) q++;
                else q--;
                ch[l[a]]^=1;
            }
        }
        //if(i==1) cout<<an;
        if(di!=-1)
        {
            bool chl[os];
            int ql=q;
            for(int a=0; a<os; a++) chl[a]=ch[a];
            if(stl or l[di]!=0)
            {
                if(chl[l[di]]) ql--;
                else ql++;
                chl[l[di]]^=1;
                stl=1;
            }
            for(int a=di-1; a>=0; a--)
            {
                //cout<<a<<" ";
                for(int b=l[a]+1; b<os; b++)
                {
                    int nq=ql;
                    if(chl[b]) nq--;
                    else nq++;
                    //if(a==1) cout<<nq<<" ";
                    an+=val[os][nq][a];
                }
                if(l[a]!=0) stl=1;
                if(stl)
                {
                    if(chl[l[a]]==0) ql++;
                    else ql--;
                    chl[l[a]]^=1;
                }
            }
            if(ql==0) an++;

            //cout<<an;

            bool chr[os];
            int qr=q;
            for(int a=0; a<os; a++) chr[a]=ch[a];
            if(chr[r[di]]) qr--;
            else qr++;
            chr[r[di]]^=1;
            str=1;
            for(int a=di-1; a>=0; a--)
            {
                for(int b=r[a]-1; b>=0; b--)
                {
                    int nq=qr;
                    if(chr[b]) nq--;
                    else nq++;
                    an+=val[os][nq][a];
                }
                if(r[a]!=0) str=1;
                if(str)
                {
                    if(chr[r[a]]==0) qr++;
                    else qr--;
                    chr[r[a]]^=1;
                }
            }
            if(qr==0) an++;
        }
        else if(q==0) an++;

        cout<<an<<"\n";
    }
}