#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch&15),ch=getchar();
    return x;
}
pair<int,int> a[1000003];
int A[1000003],B[1000003];
bool cmp(int x,int y)
{
    return a[x].second<a[y].second;
}
int la,lb;
int f[1000003];
signed main()
{
	int n=read();
    pair<int,int> p;
    for(int i=1; i<=n; i++)
    {
        p.first=read(),p.second=read();
        if(p.first<p.second) A[++la]=i;
        else B[++lb]=i;
        a[i]=p;
    }
    if(la>=lb)
    {
        printf("%d\n",la);
        for(int i=1; i<=la; i++) f[i]=A[i];
        sort(f+1,f+la+1,cmp);
        for(int i=la; i>=1; i--) printf("%d ",f[i]);
    }
    else
    {
        printf("%d\n",lb);
        for(int i=1; i<=lb; i++) f[i]=B[i];
        sort(f+1,f+lb+1,cmp);
        for(int i=1; i<=lb; i++) printf("%d ",f[i]);
    }
	return 0;
}