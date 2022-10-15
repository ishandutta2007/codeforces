#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int mod(int x)
{
        x%=10;
        x+=10;
        x%=10;
        return x;
}

const int N=(int)2e6+7;
string s;
int n;
int want[N];
int sol[10][10][10][10];

int compute(int x,int y,int a,int b)
{
        int mi=(1<<30);
        for(int f=0;f<=10 && f<mi;f++)
                for(int s=0;s<=10 && f+s<mi;s++)
                {
                        if(f==0 && s==0) continue;
                        int u=mod(x*f+y*s+a);
                        if(u==b)
                                mi=f+s;
                }
        if(mi==(1<<30))
                return -1;

        return mi-1;
}

int compute(int x,int y)
{
        int ans=0;
        for(int i=1;i<n;i++)
        {
                int z=sol[x][y][want[i]][want[i+1]];
               // cout<<x<<" "<<y<<" : "<<want[i]<<" "<<want[i+1]<<" "<<z<<"\n";
                if(z==-1)
                        return -1;
                ans+=z;
        }
        return ans;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


        string s;
        cin>>s;
    ///    s="000";
        n=(int)s.size();
        s="."+s;
        for(int i=1;i<=n;i++)
                want[i]=s[i]-'0';
      ///  cout<<compute(1,2,0,0);
      ///  return 0;

        for(int x=0;x<=9;x++)
                for(int y=0;y<=9;y++)
                        for(int a=0;a<=9;a++)
                                for(int b=0;b<=9;b++)
                                        sol[x][y][a][b]=compute(x,y,a,b);
///        cout<<compute(0,1);
///        return 0;

        for(int x=0;x<=9;x++)
        {
                for(int y=0;y<=9;y++)
                {
                        int z=compute(x,y);
                        cout<<z<<" ";
                }
                cout<<"\n";
        }

        return 0;
}
/**



**/