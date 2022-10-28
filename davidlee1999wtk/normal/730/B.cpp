#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 105
#define INF 1000000000
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int a[N];
int T,c[N],d[N],nc,nd;
char op[2];
int main()
{
    cin>>T;
    int n,i,mn,mx;
    while(T--)
    {
        nc=nd=0;
        cin>>n;
        if(n==1)
        {
            printf("! 1 1\n");
            fflush(stdout);
            continue;
        }
        for(i=1;i<n;i+=2)
        {
            printf("? %d %d\n",i,i+1);
            fflush(stdout);
            scanf("%s",op);
            if(op[0]=='<')
            {
                c[++nc]=i;
                d[++nd]=i+1;
            }
            else
            {
                c[++nc]=i+1;
                d[++nd]=i;
            }
        }
        if(i==n)
        {
            printf("? %d %d\n",i,1);
            fflush(stdout);
            scanf("%s",op);
            if(op[0]=='<')
            {
                c[++nc]=i;
            }
            else
            {
                d[++nd]=i;
            }
        }
        mn=c[1];
        mx=d[1];
        for(i=2;i<=nc;i++)
        {
            printf("? %d %d\n",mn,c[i]);
            fflush(stdout);
            scanf("%s",op);
            if(op[0]=='<')
                ;
            else
                mn=c[i];
        }
        for(i=2;i<=nd;i++)
        {
            printf("? %d %d\n",mx,d[i]);
            fflush(stdout);
            scanf("%s",op);
            if(op[0]=='>')
                ;
            else
                mx=d[i];
        }
        printf("! %d %d\n",mn,mx);
        fflush(stdout);
    }
    return 0;
}
// davidlee1999WTK 2016/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/