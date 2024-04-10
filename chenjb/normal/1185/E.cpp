#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int T;
int n,m;
char s[2100][2100],b[2100][2100];
int minx[30],miny[30],maxx[30],maxy[30];
bool check()
{
    for(int i=0;i<26;i++)
    {
        if (minx[i]==2147483647)continue;
        if (minx[i]!=maxx[i] && miny[i]!=maxy[i])return 0;
    }
    return 1;
}
int main()
{
   int T; cin>>T;
   while (T--)
   {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
        for(int i=0;i<26;i++)minx[i]=2147483647;
        for(int i=0;i<26;i++)miny[i]=2147483647;
        for(int i=0;i<26;i++)maxx[i]=-2147483647;
        for(int i=0;i<26;i++)maxy[i]=-2147483647;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if (s[i][j]!='.')minx[s[i][j]-'a']=min(minx[s[i][j]-'a'],i);
            if (s[i][j]!='.')maxx[s[i][j]-'a']=max(maxx[s[i][j]-'a'],i);
            if (s[i][j]!='.')miny[s[i][j]-'a']=min(miny[s[i][j]-'a'],j);
            if (s[i][j]!='.')maxy[s[i][j]-'a']=max(maxy[s[i][j]-'a'],j);
        }
        if (!check()){ puts("NO"); continue; }
        int tx=-1,ty=-1,maxdigit=-1;
        for(int i=25;i>=0;i--)
            if (minx[i]!=2147483647)
            {
                tx=maxx[i];
                ty=maxy[i];
                maxdigit=i;
                break;
            }
        if (maxdigit==-1){ puts("YES"); puts("0");continue; }
        for(int i=0;i<=maxdigit;i++)
            if (minx[i]==2147483647)minx[i]=tx,miny[i]=ty,maxx[i]=tx,maxy[i]=ty;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                b[i][j]='.';
        for(int i=0;i<=maxdigit;i++)
            for(int x=minx[i];x<=maxx[i];x++)
                for(int y=miny[i];y<=maxy[i];y++)
                    b[x][y]=(char)('a'+i);
        int flag=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if (s[i][j]!=b[i][j])
                    flag=0;
        if (!flag){ puts("NO"); continue; }
        puts("YES");
        cout<<maxdigit+1<<endl;
        for(int i=0;i<=maxdigit;i++)printf("%d %d %d %d\n",minx[i],miny[i],maxx[i],maxy[i]);
   }    
}