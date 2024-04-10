#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch&15),ch=getchar();
    return x;
}
int pos[1000003],a[1000003];
int X[1000003],Y[1000003],cnt;
void SWAP(int x,int y)
{
    X[++cnt]=x,Y[cnt]=y;
    swap(pos[a[x]],pos[a[y]]);
    swap(a[x],a[y]);
}
void print()
{
    printf("%d\n",cnt);
    for(int i=1; i<=cnt; i++)
    printf("%d %d\n",X[i],Y[i]);
}
signed main()
{
    int n=read();
    for(int i=1,x; i<=n; i++) x=read(),pos[x]=i,a[i]=x;
    for(int l=n/2,r=l+1; r<n; l--,r++)
    {
        if(pos[l]!=l) {
        if(abs(pos[l]-l)>=n/2)
        {
            SWAP(l,pos[l]);
        }
        else
        {
            if(n-pos[l]>=n/2)
            {
                SWAP(pos[l],n);
                SWAP(n,l);
            }
            else
            {
                SWAP(pos[l],1);
                SWAP(1,n);
                SWAP(n,l);
            }
        } }
        if(pos[r]!=r) {
        if(abs(pos[r]-r)>=n/2)
        {
            SWAP(r,pos[r]);
        }
        else
        {
            if(pos[r]-1>=n/2)
            {
                SWAP(pos[r],1);
                SWAP(1,r);
            }
            else
            {
                SWAP(pos[r],n);
                SWAP(n,1);
                SWAP(1,r);
            }
        } }
    }
    if(a[1]!=1) SWAP(1,n);
    print();
	return 0;
}