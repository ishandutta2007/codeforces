#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

int a[MAXN],b[MAXN],n,m;

bool check(int x)
{
    bool res=1;
    b[n-1]=min(m-1,a[n-1]+x);
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>b[i+1])
        {
            int y=x-m+a[i];
            if(y<0)
                res=0;
            b[i]=min(y,b[i+1]);
        }
        else
            b[i]=min(b[i+1],min(m-1,a[i]+x));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int res=-1;
    for(int i=(1<<18);i;i>>=1)
        if(!check(res+i))
            res+=i;
    res++;
    db(res)

    return 0;
}