#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool vld(vector<vector<int>>sl)
{
        int a=sl.size(),b=sl[0].size();
        for(int i=0;i<a;i++)
        {
                bool p0=0,p1=0,p2=0,p3=0,p4=0;
                for(int j=0;j<b;j++)
                {
                        if(sl[i][j]=='a') p0=1;
                        if(sl[i][j]=='e') p1=1;
                        if(sl[i][j]=='i') p2=1;
                        if(sl[i][j]=='o') p3=1;
                        if(sl[i][j]=='u') p4=1;
                }
                if(p0==0 || p1==0 || p2==0 || p3==0 || p4==0) return 0;
        }
        for(int j=0;j<b;j++)
        {
                bool p0=0,p1=0,p2=0,p3=0,p4=0;
                for(int i=0;i<a;i++)
                {
                        if(sl[i][j]=='a') p0=1;
                        if(sl[i][j]=='e') p1=1;
                        if(sl[i][j]=='i') p2=1;
                        if(sl[i][j]=='o') p3=1;
                        if(sl[i][j]=='u') p4=1;
                }
                if(p0==0 || p1==0 || p2==0 || p3==0 || p4==0) return 0;
        }
        return 1;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                if(n%i==0 && i>=5 && n/i>=5)
                {
                        int a=i,b=n/i;
                        vector<vector<int>>sl(a);
                        for(int j=0;j<a;j++)
                        {
                                sl[j].resize(b);
                        }
                        for(int i=0;i<a;i++)
                        {
                                for(int j=0;j<b;j++)
                                {
                                        if((i+j)%5==0) sl[i][j]='a';
                                        if((i+j)%5==1) sl[i][j]='e';
                                        if((i+j)%5==2) sl[i][j]='i';
                                        if((i+j)%5==3) sl[i][j]='o';
                                        if((i+j)%5==4) sl[i][j]='u';
                                }
                        }
                        if(!vld(sl)) continue;
                        for(int i=0;i<a;i++)
                        {
                                for(int j=0;j<b;j++)
                                {
                                        cout<<(char)sl[i][j];
                                }
                             //   cout<<"\n";
                        }
                        cout<<"\n";
                        return 0;
                }
        }
        cout<<"-1\n";
        return 0;
}
/**

**/