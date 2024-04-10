#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nmax=100000;
int n,k;
int v[nmax+5];
bool ap[30];

int main()
{
    cin>>n>>k;
    cin.get();
    for(int i=1;i<=n;i++)
    {char ch;
        ch=cin.get();
        ap[ch-'a']=1;
        v[i]=ch-'a';
    }
    int ma=0,mi=0,last=0;
    for(int i=0;i<26;i++)
        if(ap[i])
            ma=i;
    for(int i=25;i>=0;i--)
        if(ap[i])
            mi=i;
    if(k>n)
    {
        for(int i=1;i<=n;i++)
            cout<<char('a'+v[i]);
        for(int i=n+1;i<=k;i++)
            cout<<char(mi+'a');
        return 0;
    }
    for(int i=1;i<=k;i++)
        if(v[i]!=ma)
            last=i;
    for(int i=1;i<last;i++)
        cout<<char(v[i]+'a');
    for(int i=v[last]+1;i<26;i++)
        if(ap[i])
        {
            cout<<char('a'+i);
            break;
        }
    for(int i=last+1;i<=k;i++)
        cout<<char(mi+'a');
    return 0;
}
/**

aa
aaab

**/