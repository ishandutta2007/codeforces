#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    if(t[0]==t[1])
    {
        int c=0;
        for(char a:s) c+=(a==t[0]);
        c+=min(n-c,k);
        cout << c*(c-1)/2 << "\n";
    }
    else
    {
        int c1=0,c2=0;
        for(char c:s)
        {
            c1+=(c==t[0]);
            c2+=(c==t[1]);
        }
        int res=0;
        for(int a=0;a<=c2;a++)
        {
            for(int b=0;b<=c1&&a+b<=k;b++)
            {
                string now=s;
                int na=a,nb=b;
                for(int i=0;i<n;i++)
                {
                    if(na>0&&s[i]==t[1])
                    {
                        now[i]=t[0];
                        na--;
                    }
                }
                for(int i=n-1;i>=0;i--)
                {
                    if(nb>0&&s[i]==t[0])
                    {
                        now[i]=t[1];
                        nb--;
                    }
                }
                vector<int> one(n,0);
                vector<int> two(n,0);
                for(int i=0;i<n;i++)
                {
                    one[i]=(now[i]==t[0]);
                    if(i>0) one[i]+=one[i-1];
                }
                for(int i=n-1;i>=0;i--)
                {
                    two[i]=(now[i]==t[1]);
                    if(i<n-1) two[i]+=two[i+1];
                }
                int cnt=0;
                for(int i=0;i<n-1;i++) if(now[i]==t[0]) cnt+=two[i+1];
                vector<int> add1(n+1,0);
                vector<int> add2(n+1,0);
                int now1=0;
                int now2=0;
                for(int i=0;i<n;i++)
                {
                    if(now[i]!=t[0]&&now[i]!=t[1])
                    {
                        now1++;
                        add1[now1]=add1[now1-1];
                        if(i<n-1) add1[now1]+=two[i+1];
                    }
                }
                for(int i=n-1;i>=0;i--)
                {
                    if(now[i]!=t[0]&&now[i]!=t[1])
                    {
                        now2++;
                        add2[now2]=add2[now2-1];
                        if(i>0) add2[now2]+=one[i-1];
                    }
                }
                int z=min(k-a-b,n-c1-c2);
                for(int i=0;i<=z;i++) res=max(res,cnt+add1[i]+add2[z-i]+i*(z-i));
            }
        }
        cout << res << "\n";
    }
    return 0;
}