#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[105], b[105];
vector <int> v, u;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]%2)
            a[i]=1;
        else if(a[i]!=0)
            a[i]=2;
    }
    a[n]=1;

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
            b[j]=-1;
        if(a[i]==2)
            b[j]=-2;
        if(a[i]==0)
        {
            while(a[i]==0)
            {
                i++;
                b[j]++;
            }
            i--;
        }
        j++;
    }
    int m=j;

    if(m==1)
    {
        if(n==1)
            cout << 0;
        else cout << 1;
        return 0;
    }

    int k1=0;
    int k2=0;
    for(int i=0;i<m;i++)
    {
        if(b[i]==-1)
            k1++;
        if(b[i]==-2)
            k2++;
    }

    int ka=n-n/2-k1;
    int kb=n/2-k2;
    int kc=ka;
    int kd=kb;
    int s=0;
    for(int i=0;i<m;i++)
        if(b[i]>0)
    {
        if(i==0 || i==m-1)
            s++;
        else if(b[i-1]==b[i+1])
            s+=2;
        else s++;
    }
    else if(i!=0 && b[i-1]<0 && b[i-1]!=b[i])
        s++;

    for(int i=1;i<m-1;i++)
        if(b[i]>0 && b[i-1]==b[i+1])
    {
        if(b[i-1]==-1)
            v.push_back(b[i]);
        else u.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    sort(u.begin(), u.end());

    /*for(int i=0;i<m;i++)
        cout << b[i] << ' ';
    cout << endl;*/

    int x=s;
    int Min=x;
    for(auto to:v)
        if(ka>=to)
    {
        ka-=to;
        x-=2;
    }
    for(auto to:u)
        if(kb>=to)
    {
        kb-=to;
        x-=2;
    }
    Min=min(Min, x);
    //cout << x << ' ';
    ka=kc;
    kb=kd;

    x=s;
    if(b[0]>0)
    {
        if(b[1]==-1 && ka>=b[0])
        {
            ka-=b[0];
            x--;
        }
        if(b[1]==-2 && kb>=b[0])
        {
            kb-=b[0];
            x--;
        }
    }
    for(auto to:v)
        if(ka>=to)
    {
        ka-=to;
        x-=2;
    }
    for(auto to:u)
        if(kb>=to)
    {
        kb-=to;
        x-=2;
    }
    Min=min(Min, x);
    //cout << x << ' ';
    ka=kc;
    kb=kd;

    x=s;
    if(b[m-1]>0)
    {
        if(b[m-2]==-1 && ka>=b[m-1])
        {
            ka-=b[m-1];
            x--;
        }
        if(b[m-2]==-2 && kb>=b[m-1])
        {
            kb-=b[m-1];
            x--;
        }
    }
    for(auto to:v)
        if(ka>=to)
    {
        ka-=to;
        x-=2;
    }
    for(auto to:u)
        if(kb>=to)
    {
        kb-=to;
        x-=2;
    }
    Min=min(Min, x);
    //cout << x << ' ';
    ka=kc;
    kb=kd;

    x=s;
    if(b[0]>0)
    {
        if(b[1]==-1 && ka>=b[0])
        {
            ka-=b[0];
            x--;
        }
        if(b[1]==-2 && kb>=b[0])
        {
            kb-=b[0];
            x--;
        }
    }
    if(b[m-1]>0)
    {
        if(b[m-2]==-1 && ka>=b[m-1])
        {
            ka-=b[m-1];
            x--;
        }
        if(b[m-2]==-2 && kb>=b[m-1])
        {
            kb-=b[m-1];
            x--;
        }
    }
    for(auto to:v)
        if(ka>=to)
    {
        ka-=to;
        x-=2;
    }
    for(auto to:u)
        if(kb>=to)
    {
        kb-=to;
        x-=2;
    }
    Min=min(Min, x);
    //cout << x << ' ';
    ka=kc;
    kb=kd;
    cout << Min;
}