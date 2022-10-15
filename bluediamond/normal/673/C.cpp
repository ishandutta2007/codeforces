#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=5000+5;
int n,v[N];
int cnt[N];
int ap[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int st=1;st<=n;st++)
    {
        for(int j=1;j<=n;j++)
            ap[j]=0;
        int cur=0;
        for(int dr=st;dr<=n;dr++)
        {
            ap[v[dr]]++;
            if(ap[v[dr]]>ap[cur])
                cur=v[dr];
            else
                if(ap[v[dr]]==ap[cur] && v[dr]<cur)
                    cur=v[dr];
            cnt[cur]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<"\n";
    return 0;
}