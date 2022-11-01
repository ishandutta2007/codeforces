#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        s=string(n*m-1,'0')+s;
        vector<int> d(n*m,0);
        int c=0;
        for(int i=0;i<m-1;i++) c+=(s[i]-'0');
        for(int i=m-1;i<2*n*m-1;i++)
        {
            c+=(s[i]-'0');
            if(c==0)
            {
                int p=i-(m-1);
                int one=(p%m);
                int l=max(one,p-((n*m-1)-m+1));
                int r=p;
                d[l]++;
                if(r+m<n*m) d[r+m]--;
            }
            c-=(s[i-(m-1)]-'0');
        }
        vector<int> e(n*m,0);
        for(int i=0;i<m;i++)
        {
            c=0;
            for(int j=0;j<n-1;j++) c+=(s[i+j*m]-'0');
            for(int j=n-1;i+j*m<2*n*m-1;j++)
            {
                c+=(s[i+j*m]-'0');
                if(c==0)
                {
                    int p=(i+(j-n+1)*m);
                    int l=max(0,i+j*m-(n*m-1));
                    int r=p;
                    e[l]++;
                    if(r+1<n*m) e[r+1]--;
                }
                c-=(s[i+(j-n+1)*m]-'0');
            }
        }
        for(int i=m;i<n*m;i++) d[i]+=d[i-m];
        for(int i=1;i<n*m;i++) e[i]+=e[i-1];
        for(int i=0;i<n*m;i++) cout << n+m-(d[i]+e[i]) << " \n"[i==n*m-1];
    }
    return 0;
}