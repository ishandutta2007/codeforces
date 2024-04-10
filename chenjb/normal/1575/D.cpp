#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
char ts[20],s[20];
long long ans=0;
int n;
void work(int x,int y)
{
    //cout<<x<<" "<<y<<" "<<endl;
    //for(int i=1;i<=n;i++)putchar(s[i]); puts("");
    //cout<<s[n-1]<<" "<<s[n]<<endl;
    if (n<2)return;
    //puts("fuck");
    if (s[n-1]!='_' && s[n-1]!=('0'+x))return;
    //puts("fuck");
    if (s[n]!='_' && s[n]!=('0'+y))return;
    s[n-1]=('0'+x);
    s[n]=('0'+y);
   // for(int i=1;i<=n;i++)putchar(s[i]); puts("");
    if (s[1]=='0')return;
    //puts("fuck");
    long long t=1;
    for(int i=1;i<=n-2;i++)
        if (s[i]=='_')
        {
            if (i==1)t=t*9ll; else t=t*10ll;
        }
    ans+=t;
}
int main()
{
    scanf("%s",ts+1);
    n=strlen(ts+1);
    if (n==1)
    {
        if (ts[1]=='0' || ts[1]=='_' || ts[1]=='X') puts("1"); else puts("0");
        return 0;
    }
    int flagx=0;
    for(int i=1;i<=n;i++)
        if (ts[i]=='X')flagx=1;
    for(int i=0;i<=(flagx==1?9:0);i++)
    {
        for(int j=1;j<=n;j++)s[j]=ts[j];
        for(int j=1;j<=n;j++)
            if (s[j]=='X')s[j]=('0'+i);
        work(0,0);
        for(int j=1;j<=n;j++)s[j]=ts[j];
        for(int j=1;j<=n;j++)
            if (s[j]=='X')s[j]=('0'+i);
        work(2,5);
        for(int j=1;j<=n;j++)s[j]=ts[j];
        for(int j=1;j<=n;j++)
            if (s[j]=='X')s[j]=('0'+i);
        work(5,0);
        for(int j=1;j<=n;j++)s[j]=ts[j];
        for(int j=1;j<=n;j++)
            if (s[j]=='X')s[j]=('0'+i);
        work(7,5);
    }
    cout<<ans<<endl;
    return 0;
}