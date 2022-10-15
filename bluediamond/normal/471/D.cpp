#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000+5;

int n,m;
int a[N];
int s[N];
int pat[N];
int ps[N];

inline void LP()
{
    ps[0]=0;
    int i=1,cur=0;
    while(i<m)
    {
        if(pat[i]==pat[cur])
        {
            cur++;
            ps[i]=cur;
            i++;
        }
        else
        {
            if(cur==0)
            {
                i++;
            }
            else
            {
                cur=ps[cur-1];
            }
        }
    }
}

vector<int>ans;

inline void KMP()
{
    int i=0;
    int j=0;
    while(i<n)
    {
        if(s[i]==pat[j])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            ans.push_back(i-m);
            j=ps[j-1];
        }
        if(i<n && s[i]!=pat[j])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=ps[j-1];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    if(m==1)
    {
        cout<<n<<"\n";
        return 0;
    }
    for(int i=0;i<n;i++) cin>>a[i];
    n--;
    for(int i=1;i<=n;i++)
    {
        s[i-1]=a[i]-a[i-1];
    }
    for(int i=0;i<m;i++) cin>>a[i];
    m--;
    for(int i=1;i<=m;i++)
    {
        pat[i-1]=a[i]-a[i-1];
    }
    LP();
    KMP();
    cout<<ans.size()<<"\n";
    return 0;
    for(int i=1;i<=n;i++)
    {
        cout<<s[i-1]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=m;i++)
    {
        cout<<pat[i-1]<<" ";
    }
    cout<<"\n";
    return 0;
}