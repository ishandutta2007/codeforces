#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
vector<pair<char,int> > a,b;
char s1[1100000],s2[1100000];
int main()
{
    int T; cin>>T;
    while (T--)
    {
        scanf("%s",s1+1);
        int n=strlen(s1+1); 
        int pre=1;
        char prec=s1[1];
        a.clear(); 
        b.clear();
        
        for(int i=2;i<=n+1;i++)
        {
            if (i<=n && s1[i]==s1[i-1]){ pre++; continue; }
            a.pb(mp(prec,pre));
            prec=s1[i];
            pre=1;
        }
        scanf("%s",s2+1);
        int m=strlen(s2+1); 
        pre=1;
        prec=s2[1];
        for(int i=2;i<=m+1;i++)
        {
            if (i<=m && s2[i]==s2[i-1]){ pre++; continue; }
            b.pb(mp(prec,pre));
            prec=s2[i];
            pre=1;
        }
        int flag=1;
        if (a.size()!=b.size()){ puts("NO"); continue; }
        for(int i=0;i<a.size();i++)
            if (a[i].first!=b[i].first || a[i].second>b[i].second)flag=0;
        if (flag)puts("YES"); else puts("NO");
    }
    
    return 0;
}