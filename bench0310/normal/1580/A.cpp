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
        vector<string> s(n+1);
        for(int i=1;i<=n;i++)
        {
            cin >> s[i];
            s[i]="$"+s[i];
        }
        vector up(n+1,vector(m+1,int(0)));
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) up[i][j]=(up[i-1][j]+(s[i][j]-'0'));
        auto zero=[&](int a,int b,int c)->int{return (b-a+1-(up[b][c]-up[a-1][c]));};
        auto one=[&](int a,int b,int c)->int{return (b-a+1-zero(a,b,c));};
        auto mid=[&](int a,int b,int c)->int{return zero(a,a,c)+one(a+1,b-1,c)+zero(b,b,c);};
        auto side=[&](int a,int b,int c)->int{return zero(a+1,b-1,c);};
        int res=n*m;
        for(int a=1;a<=n;a++)
        {
            for(int b=a+4;b<=n;b++)
            {
                vector<int> sum(m+1,0);
                for(int j=1;j<=m;j++) sum[j]=(sum[j-1]-side(a,b,j-1)+mid(a,b,j-1)+side(a,b,j));
                vector<int> best(m+2,n*m);
                for(int j=m;j>=1;j--) best[j]=min(best[j+1],sum[j]);
                for(int j=1;j+3<=m;j++) res=min(res,best[j+3]-sum[j]-mid(a,b,j)+2*side(a,b,j));
            }
        }
        cout << res << "\n";
    }
    return 0;
}