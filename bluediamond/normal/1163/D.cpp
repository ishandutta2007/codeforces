#include <cstdio>
#include <iostream>

using namespace std;

void buildPS(string pat,int ps[])
{
    int m=pat.size();
    int i=1,cur=0;
    while(i<m)
    {
        if(pat[i]==pat[cur])
        {
            cur++;
            ps[i]=cur;
            i++;
        }
        else
        {
            if(cur==0)
            {
                i++;
            }
            else
            {
                cur=ps[cur-1];
            }
        }
    }
}

const int N=1000+3;
const int K=50+3;
const int INF=(int)1e9;
string s;
string a,b;
int x[K],y[K];
int dp[N][K][K];
int lena,lenb;

int matcha,matchb;
char ch;

void kolbarA()
{
   /// cout<<"! "<<matcha<<" : "<<ch<<" "<<a[matcha]<<"\n";
    if(ch==a[matcha])
    {
        matcha++;
        return;
    }
    if(matcha==lena)
    {
        matcha=x[matcha-1];
    }
    ///cout<<" : "<<ch<<" , "<<matcha<<" "<<a[matcha]<<"\n";
    if(ch!=a[matcha])
    {
        if(matcha==0)
        {
            return;
        }
        else
        {
            matcha=x[matcha-1];
            kolbarA();
            return;
        }
    }
    kolbarA();
}

void kolbarB()
{
    if(ch==b[matchb])
    {
        matchb++;
        return;
    }
    if(matchb==lenb)
    {
        matchb=y[matchb-1];
    }
    if(ch!=b[matchb])
    {
        if(matchb==0)
        {
            return;
        }
        else
        {
            matchb=y[matchb-1];
            kolbarB();
            return;
        }
    }
    kolbarB();
}

int noui[K];
int nouj[K];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s>>a>>b;
    int n=s.size();
    buildPS(a,x);
    buildPS(b,y);

    lena=a.size(),lenb=b.size();
    for(int i=0;i<N;i++) for(int j=0;j<K;j++) for(int k=0;k<K;k++) dp[i][j][k]=-INF;
    dp[0][0][0]=0;
    s="."+s;

  ///  return 0;
    for(int id=1;id<=n;id++)
    {
        ch=s[id];
        char st=ch,dr=ch;
        if(ch=='*')
        {
            st='a';
            dr='z';
        }
        for(ch=st;ch<=dr;ch++)
        {
         ///   cout<<ch<<" : ";
            for(int i=0;i<=lena;i++)
            {
           ///     cout<<i<<" ";
                matcha=i;
                kolbarA();
                noui[i]=matcha;
            ///    cout<<"end\n";
            }
         ///   cout<<"done\n";
            for(int j=0;j<=lenb;j++)
            {
                matchb=j;
                kolbarB();
                nouj[j]=matchb;
            }
            for(int i=0;i<=lena;i++)
            {
                for(int j=0;j<=lenb;j++)
                {
                    if(dp[id-1][i][j]==-INF) continue;
                    dp[id][noui[i]][nouj[j]]=max(dp[id][noui[i]][nouj[j]],dp[id-1][i][j]+(noui[i]==lena)-(nouj[j]==lenb));
                   /** if(id==4 && noui[i]==4 && nouj[j]==0)
                    {
                        cout<<" : "<<id-1<<" "<<i<<" "<<j<<"\n";
                    }**/
                }
            }
        }
    }
    int res=-INF;
    for(int i=0;i<=lena;i++)
    {
        for(int j=0;j<=lenb;j++)
        {
            res=max(res,dp[n][i][j]);
            /**if(dp[n][i][j]==0)
            {
                cout<<i<<" "<<j<<"\n";
            }**/
        }
    }
    cout<<res<<"\n";
    return 0;
}
/**

s
cc
b

**/