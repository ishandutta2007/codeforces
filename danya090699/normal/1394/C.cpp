#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10, inf=1e9;
int prefl[sz], prefr[sz], sufl[sz], sufr[sz], mi=inf, ma=0;
int de(int x, int y)
{
    return x/y+(x%y>0);
}
int main()
{
    for(int a=0; a<sz; a++)
    {
        prefl[a]=-inf, prefr[a]=inf;
        sufl[a]=-inf, sufr[a]=inf;
    }
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int bq=0, nq=0;
        for(int b=0; b<s.size(); b++)
        {
            if(s[b]=='B') bq++;
            else nq++;
        }
        prefl[bq]=max(prefl[bq], nq-bq);
        prefr[bq]=min(prefr[bq], nq);
        sufl[bq]=max(sufl[bq], nq);
        sufr[bq]=min(sufr[bq], nq-bq);

        mi=min(mi, bq), ma=max(ma, bq);
    }
    for(int a=1; a<sz; a++)
    {
        prefl[a]=max(prefl[a], prefl[a-1]);
        prefr[a]=min(prefr[a], prefr[a-1]);
    }
    for(int a=sz-2; a>=0; a--)
    {
        sufl[a]=max(sufl[a], sufl[a+1]);
        sufr[a]=min(sufr[a], sufr[a+1]);
    }
    int an=inf, B, N;
    for(int a=0; a<sz; a++)
    {
        int q=max(a-mi, ma-a), nq;
        int l=max(prefl[a]+a, sufl[a])-q;
        int r=min(prefr[a], sufr[a]+a)+q;
        if(l<=r) nq=r;
        else nq=r+de(l-r, 2), q+=de(l-r, 2);

        if(q<=an) an=q, B=a, N=nq;
    }
    cout<<an<<"\n";
    for(int a=0; a<B; a++) printf("B");
    for(int a=0; a<N; a++) printf("N");
}