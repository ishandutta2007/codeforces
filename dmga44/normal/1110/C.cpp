#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

map<int,int> m;

int gcd(int a,int b)
{
    while(b)
    {
        int t=a;
        a=b;
        b=t%b;
    }
    return a;
}

void prep()
{
    int x=1;
    for(int i=0;i<24;i++)
    {
        x=(x<<1)+1;
        int res=0;
        for(int j=2;j<=(sqrt(x)+1);j++)
            if(x%j==0)
                res=max(res,x/j);
        if(!res)
            res=1;
        m[x]=res;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    prep();

    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        if(((a+1)&(-(a+1)))!=(a+1))
        {
            a++;
            while((a&-a)!=a)
                a+=(a&-a);
            db(a-1)
        }
        else
            db(m[a])
    }

    return 0;
}