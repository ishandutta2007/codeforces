#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int c[20][sz], st[sz];
void build(string &s)
{
    int n=s.size();
    int p[n], pn[n], cnt[max(n, 26)];
    for(int a=0; a<26; a++) cnt[a]=0;
    for(int a=0; a<n; a++) cnt[s[a]-'a']++;
    for(int a=1; a<26; a++) cnt[a]+=cnt[a-1];
    for(int a=0; a<n; a++)
    {
        cnt[s[a]-'a']--, p[cnt[s[a]-'a']]=a;
    }
    c[0][p[0]]=0;
    int cq=1;
    for(int a=1; a<n; a++)
    {
        if(s[p[a]]!=s[p[a-1]]) cq++;
        c[0][p[a]]=cq-1;
    }
    for(int i=1; (1<<i)<=n; i++)
    {
        for(int a=0; a<n; a++)
        {
            pn[a]=p[a]-(1<<(i-1));
            if(pn[a]<0) pn[a]+=n;
        }
        for(int a=0; a<n; a++) cnt[a]=0;
        for(int a=0; a<n; a++) cnt[c[i-1][a]]++;
        for(int a=1; a<n; a++) cnt[a]+=cnt[a-1];
        for(int a=n-1; a>=0; a--)
        {
            cnt[c[i-1][pn[a]]]--, p[cnt[c[i-1][pn[a]]]]=pn[a];
        }
        c[i][p[0]]=0;
        int cq=1;
        for(int a=1; a<n; a++)
        {
            int p1=(p[a-1]+(1<<(i-1)))%n, p2=(p[a]+(1<<(i-1)))%n;
            if(c[i-1][p[a-1]]!=c[i-1][p[a]] or c[i-1][p1]!=c[i-1][p2]) cq++;
            c[i][p[a]]=cq-1;
        }
    }
    for(int i=0; (1<<i)<=n; i++)
    {
        for(int a=(1<<i); a<min(n+1, (1<<(i+1))); a++) st[a]=i;
    }
}
bool comp(int p1, int p2, int l)
{
    int i=st[l];
    return (c[i][p1]==c[i][p2] and c[i][p1+l-(1<<i)]==c[i][p2+l-(1<<i)]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    build(s);
    int ar[n];
    for(int a=0; a<=(n-1-a); a++) ar[a]=a-1;
    for(int a=0; a<(n-1-a); a++)
    {
        int l=-1, r=a+1;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(comp(a-mid, (n-1-a)-mid, mid*2+1)) l=mid;
            else r=mid;
        }
        if(l!=-1) ar[a-l]=max(ar[a-l], a);
    }
    for(int a=0; a<=(n-1-a); a++)
    {
        printf("%d ", 2*(ar[a]-a)+1);
        ar[a+1]=max(ar[a+1], ar[a]);
    }
}