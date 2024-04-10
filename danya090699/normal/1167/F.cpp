#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, sz=5e5+10;
int fen[2][sz];
void cha(int i, int p, int va)
{
    while(p<sz)
    {
        fen[i][p]+=va, p=p|(p+1);
    }
}
int que(int i, int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[i][p], p=(p&(p+1))-1;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a].first);
        ar[a].second=a;
    }
    sort(ar, ar+n);
    for(int a=0; a<n; a++)
    {
        int p=ar[a].second, x=ar[a].first;
        int lsu=que(0, p), rsu=que(1, n)-que(1, p);
        int cu=(lsu*(n-p)+rsu*(p+1)+(p+1)*(n-p))%mod;
        an=(an+cu*x)%mod;
        cha(0, p, p+1), cha(1, p+1, n-p);
    }
    cout<<an;
}