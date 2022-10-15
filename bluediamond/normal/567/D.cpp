#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int)2e5+5;
int n,cnt,a;
int q;

set<int>ind;
set<int>::iterator it;

inline int f(int len)
{
    return (len+1)/(a+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>cnt>>a;
    cin>>q;
    ind.insert(0);
    ind.insert(n+1);
    int cur=f(n);
    for(int j=1;j<=q;j++)
    {
        int poz;
        cin>>poz;
            it=ind.lower_bound(poz);
        int dr=*it;
        it--;
        int st=*it;
        int init=f(dr-st-1);
        ind.insert(poz);
        int a=f(poz-st-1);
        int b=f(dr-poz-1);
        cur-=init;
        cur+=a;
        cur+=b;
        if(cur<cnt)
        {
            cout<<j<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
/**

1 2 3 * 5 6 7 * 9 10 11

**/