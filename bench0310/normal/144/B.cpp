#include <bits/stdc++.h>

using namespace std;

int dist(int a,int b,int c,int d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a>c) swap(a,c);
    if(b>d) swap(b,d);
    int n;
    scanf("%d",&n);
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++) for(int j=0;j<3;j++) scanf("%d",&v[i][j]);
    int res=0;
    for(int x=a;x<=c;x++)
    {
        bool ok=0;
        for(int i=0;i<n;i++) if(dist(x,b,v[i][0],v[i][1])<=v[i][2]*v[i][2]) ok=1;
        res+=(ok==0);
        ok=0;
        for(int i=0;i<n;i++) if(dist(x,d,v[i][0],v[i][1])<=v[i][2]*v[i][2]) ok=1;
        res+=(ok==0);
    }
    for(int y=b+1;y<=d-1;y++)
    {
        bool ok=0;
        for(int i=0;i<n;i++) if(dist(a,y,v[i][0],v[i][1])<=v[i][2]*v[i][2]) ok=1;
        res+=(ok==0);
        ok=0;
        for(int i=0;i<n;i++) if(dist(c,y,v[i][0],v[i][1])<=v[i][2]*v[i][2]) ok=1;
        res+=(ok==0);
    }
    printf("%d\n",res);
    return 0;
}