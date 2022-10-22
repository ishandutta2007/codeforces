#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
int n, l[100005], r[100005], k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> s;
    int n=s.size();
    for(int i=0;i<n-1;i++)
    {
        r[i]=i+1;
        l[i+1]=i;
    }
    l[0]=-1;
    r[n-1]=n;
    int k=0;

    for(int i=0;i<n-1;i++)
    {
        int x=i;
        int y=r[i];
        while(x>=0 && y<n && s[x]==s[y])
        {
            k++;
            if(y<n && r[y]<n)
                l[r[y]]=l[x];
            if(x>=0 && l[x]>=0)
                r[l[x]]=r[y];


            int lx=l[x];
            int ry=r[y];
            r[x]=n;
            r[y]=n;
            l[x]=-1;
            l[y]=-1;
            x=lx;
            y=ry;
        }
    }

    if(k%2)
        cout << "Yes";
    else cout << "No";
}