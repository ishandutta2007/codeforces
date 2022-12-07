#include <bits/stdc++.h>
using namespace std;
const int sz=1e5;
int ar[2][sz], add[sz];
bool check(int i)
{
    if(add[i]==0) return false;

    int v1=ar[0][i], v2=ar[0][i+1];
    if(add[i]>0) v1++, v2++;
    else v1--, v2--;
    if(v1<0 or v2<0 or v1>9 or v2>9 or (i==0 and v1==0)) return false;
    else return true;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<2; i++)
    {
        string s;
        cin>>s;
        for(int a=0; a<n; a++) ar[i][a]=s[a]-'0';
    }
    set <int> se;
    long long an=0;
    for(int a=0; a<n; a++)
    {
        int cu=ar[0][a];
        if(a) cu+=add[a-1];
        add[a]=ar[1][a]-cu;
        an+=abs(add[a]);
        if(a+1<n and check(a)) se.insert(a);
    }
    if(add[n-1]!=0)
    {
        cout<<-1;
        return 0;
    }
    printf("%lld\n", an);
    for(int a=0; a<min(an, 1ll*sz); a++)
    {
        int p=*se.begin(), cu=(add[p]>0) ? 1 : -1;
        printf("%d %d\n", p+1, cu);
        ar[0][p]+=cu, ar[0][p+1]+=cu, add[p]-=cu;
        se.erase(se.begin());
        if(check(p)) se.insert(p);
        if(p)
        {
            se.erase(p-1);
            if(check(p-1)) se.insert(p-1);
        }
        if(p+2<n)
        {
            se.erase(p+1);
            if(check(p+1)) se.insert(p+1);
        }
    }
}