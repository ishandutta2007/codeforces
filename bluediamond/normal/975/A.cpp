#include <bits/stdc++.h>

using namespace std;

const int N=1234;

struct word
{
    int ap[30];
};
bool cmp(word a,word b)
{
    for(int i=0;i<26;i++)
        if(a.ap[i]!=b.ap[i])
            return a.ap[i]<b.ap[i];
    return 0;
}
bool eq(word a,word b)
{
    for(int i=0;i<26;i++)
        if(a.ap[i]!=b.ap[i])
            return 0;
    return 1;
}
word v[N+5];
int n,poz=1;

char s[N*N+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin>>n;
    cin.get();
    cin.getline(s,N*N+5);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]==' ')
        {
            poz++;
            continue;
        }
        v[poz].ap[s[i]-'a']=1;
    }
    sort(v+1,v+n+1,cmp);
    int nr=1;
    for(int i=2;i<=n;i++)
        if(eq(v[i],v[i-1])==0)
            nr++;
    cout<<nr;
    return 0;
}