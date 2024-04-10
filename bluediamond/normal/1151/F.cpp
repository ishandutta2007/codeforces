#include <bits/stdc++.h>

using namespace std;

const int MOD=(int)1e9+7;

int add(int a,int b)
{
        a+=b;
        if(a>=MOD) return a-MOD;
        if(a<0) return a+MOD;
        return a;
}

int mul(int a,int b)
{
        return a*(long long)b%MOD;
}

int expow(int a,int b)
{
        int r=1;
        while(b)
        {
                if(b&1)
                {
                        r=mul(r,a);
                }
                a=mul(a,a);
                b>>=1;
        }
        return r;
}

int dv(int a,int b)
{
        return mul(a,expow(b,MOD-2));
}

#define matrix vector <vector <int>>

matrix operator * (matrix a,matrix b)
{
        int n=a.size(),m=a[0].size();
        matrix res;
        res.resize(n);
        for(int j=0;j<n;j++)
        {
                res[j].resize(m,0);
        }
        for(int r=0;r<n;r++)
        {
                for(int c=0;c<m;c++)
                {
                        for(int k=0;k<m;k++)
                        {
                                res[r][c]=add(res[r][c],mul(a[r][k],b[k][c]));
                        }
                }
        }
        return res;
}
matrix power(matrix a,int b)
{
        int n=a.size();
        matrix res;
        res.resize(n);
        for(int i=0;i<n;i++)
        {
                res[i].resize(n,0);
                res[i][i]=1;
        }
        while(b)
        {
                if(b&1)
                {
                        res=res*a;
                }
                a=a*a;
                b>>=1;
        }
        return res;
}

int get_sol(int ans,int n,int k)
{
        int ugar=n*(n-1)/2,put=expow(ugar,k);
        return dv(ans,put);
}

/// match0, match1
/// cnt0, cnt1

const int N=100+7;
int n,k,v[N];
int good[N];
int cnt0=0,cnt1=0;

int get_match1(int match0)
{
        int one_in_zero=cnt0-match0;
        return (cnt1-one_in_zero);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>k;
        for(int i=1;i<=n;i++) {cin>>v[i]; good[i]=v[i];}
        sort(good+1,good+n+1);
        for(int i=1;i<=n;i++) {cnt0+=(v[i]==0); cnt1+=(v[i]==1);}
        int match0=0;
        for(int i=1;i<=n;i++) {match0+=(v[i]==0 && good[i]==0);}
        matrix init(1);
        init[0].resize(cnt0+1,0); init[0][match0]=1;
        matrix second(cnt0+1);
        for(int j=0;j<=cnt0;j++)
        {
                second[j].resize(cnt0+1,0);
        }
                for(int m0=0;m0<=cnt0;m0++)
                {
                        /// facem push la urmatorul
                        int m1=get_match1(m0);
                        int inv0=(cnt0-m0),inv1=(cnt1-m1);
                        int scad=m0*m1;
                        int adun=inv0*inv1;
                        int same=n*(n-1)/2-scad-adun;
                        if(adun>0)
                        {
                                second[m0][m0+1]=add(second[m0][m0+1],adun);
                        }
                        if(scad>0)
                        {
                                second[m0][m0-1]=add(second[m0][m0-1],scad);
                        }
                        if(same>0)
                        {
                                second[m0][m0]=add(second[m0][m0],same);
                        }
                }
        /**for(int j=0;j<=cnt0;j++)
        {
                cout<<"b["<<j<<"] = ";
                for(int i=0;i<=cnt0;i++)
                {
                         cout<<"a["<<i<<"] * "<<second[i][j];
                         if(i<cnt0)
                         {
                                 cout<<" + ";
                         }
                }
                cout<<"\n";
        }
        cout<<"\n\n";**/
        init=init*power(second,k);
        /**for(int j=1;j<=k;j++)
        {
                for(int i=0;i<=cnt0;i++) cout<<dp[j][i]<<" ";
                cout<<"\n";
                for(int i=0;i<=cnt0;i++) cout<<init[0][i]<<" ";
                cout<<"\n\n\n";
                init=init*second;
        }**/
        cout<<get_sol(init[0][cnt0],n,k)<<"\n";
        return 0;
}
/**

[ x y z]  [     ]
          [     ]  = [ xn yn zn ]
          [     ]

        b[j] = a[1] * b[1][j] + a[2] * b[2][j] + a[3] * b[3][j]

**/
/**
0 1 0
=>
1 0 0 m0 = 1
0 1 0 m0 = 1
0 0 1 m0 = 2


0 1 0 m0 = 1
0 0 1 m0 = 2
1 0 0 m0 = 1
1 0 0 m0 = 1
0 1 0 m0 = 1
0 0 1 m0 = 2
0 0 1 m0 = 2
1 0 0 m0 = 1
0 1 0 m0 = 1

**/