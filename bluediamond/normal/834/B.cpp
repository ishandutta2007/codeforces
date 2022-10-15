#include <iostream>
using namespace std;
int st[30],dr[30];
bool ver[30];
int f[1000005];
int v[1000005];
int main()
{
    int n,k,i;
    cin>>n>>k;
    cin.get();
    for(i=1;i<=n;i++)
        {
            char ch;
            ch=cin.get();
            v[i]=ch-'A';
        }
    for(i=1;i<=n;i++)
    {
        if(!ver[v[i]])
        {
            int j;
            st[v[i]]=i;
            for(j=n;j>=1;j--)
                if(v[j]==v[i])
                {
                    dr[v[i]]=j;
                    break;
                }
            ver[v[i]]=1;
        }
    }
    for(i=0;i<26;i++)
    {
        int j;
        for(j=st[i];j<=dr[i];j++)
            f[j]++;
    }
    for(i=1;i<=n;i++)
        if(f[i]>k)
        {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
    return 0;
}