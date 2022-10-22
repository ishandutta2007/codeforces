#include <bits/stdc++.h>

using namespace std;
const int INF=1e9;

int n, d, a[105], x[105], y[105], used[105], s[105];

int main()
{
    cin >> n >> d;
    for(int i=1;i<n-1;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i];
    int L=0;
    int R=1e9;
    while(R-L>1)
    {
        for(int i=0;i<105;i++)
            used[i]=0;
        int M=(L+R)/2;
        s[0]=M;
        for(int i=1;i<n;i++)
            s[i]=-INF;
        for(int i=0;i<n;i++)
        {
            int Max=0;
            for(int j=0;j<n;j++)
                if(used[j]==0)
                if(used[Max]!=0 || s[j]>s[Max])
                    Max=j;
            used[Max]=1;
            for(int j=0;j<n;j++)
                if(used[j]==0 && s[Max]-d*abs(x[j]-x[Max])-d*abs(y[j]-y[Max])+a[j]>=0)
                    s[j]=max(s[j], s[Max]-d*abs(x[j]-x[Max])-d*abs(y[j]-y[Max])+a[j]);
        }
        if(s[n-1]>=0)
            R=M;
        else L=M;
    }
    cout << R;
}