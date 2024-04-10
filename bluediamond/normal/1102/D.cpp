#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)3e5+7;

int n;
string s;
int v[N];
int f[3];
int cnt[3][3]; /// i -> j

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        v[i]=(s[i]-'0');
        f[v[i]]++;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            while(f[j]<n/3 && f[i]>n/3)
            {
                cnt[i][j]++;
                f[j]++;
                f[i]--;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<i;j++)
        {
            for(int p=0;p<n && cnt[i][j];p++)
            {
                if(v[p]==i)
                {
                    v[p]=j;
                    cnt[i][j]--;
                }
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=2;j>i;j--)
        {
            for(int p=n-1;p>=0 && cnt[i][j];p--)
            {
                if(v[p]==i)
                {
                    v[p]=j;
                    cnt[i][j]--;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i];
    }
  //  cout<<"\n";
    return 0;
}
/**




**/