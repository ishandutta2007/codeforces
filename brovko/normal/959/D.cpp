#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 doijwfojeoif

using namespace std;

int n, a[100005], used[10000005], np[10000005];

int f(int x)
{
    int y=x;
    for(int i=2;i*i<=x;i++)
        while(x%i==0)
    {
        x/=i;
        if(used[i])
            return 0;
    }
    if(used[x])
        return 0;

    for(int i=2;i*i<=y;i++)
        while(y%i==0)
    {
        y/=i;
        used[i]=1;
    }
    if(y>1)
        used[y]=1;
    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=2;i*i<10000005;i++)
        if(np[i]==0)
            for(int j=i*i;j<10000005;j+=i)
                np[j]=1;

    for(int i=0;i<n;i++)
    {
        if(f(a[i]))
            cout << a[i] << ' ';
        else
        {
            while(f(a[i])==0)
                a[i]++;
            cout << a[i] << ' ';
            for(int j=2;j<10000005;j++)
            {
                if(i==n-1)
                    return 0;
                if(used[j]==0 && np[j]==0)
                {
                    cout << j << ' ';
                    i++;
                }
            }
        }
    }
}