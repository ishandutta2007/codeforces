//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
    register ll r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
    if(x<0)putchar('-'),x=-x;
    register short a[20]={},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
typedef unsigned int ull;
const int B=343;
char s[50011];
int n,sz;
int main()
{
    scanf("%s",s);
    n=strlen(s);
//  for(int i=0;i<50000;i++)s[i]=rand()%26+'a';
//  n=50000;
    for(int i=1;i<=n/2;i++)
    {
        int tmp=-1,cnt=0;
        for(int j=i+1;j<=n;j++)
        {
            if(s[j-1]==s[j-1-i])cnt++;else cnt=0;
            if(cnt==i)
            {
                tmp=j;
                break;
            }
        }
        if(tmp!=-1)
        {
            for(int j=tmp-i;j<n;j++)
            {
                s[j-i]=s[j];
            }
            n=n-i;
            i--;
        }
    }
    for(int i=0;i<n;i++)putchar(s[i]);
    return 0;
}