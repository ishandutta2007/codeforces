#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define N 1000
using namespace std;
int T,n;
inline int query(int i,int j,int k)
{
    int ret;
    cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
    cin>>ret;
    return ret;
}
inline void print(int i,int j)
{
    cout<<"! "<<i<<" "<<j<<endl;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int maxn=query(1,2,3),i=3,j=1;
        bool sf=0;
        for(int k=4;k<=n;++k)
        {
            int temp=query(1,2,k);
            if(temp!=maxn) sf=1;
            if(temp>maxn) maxn=temp,i=k;
        }
        if(!sf)
        {
            bool sf2=0;
            for(int k=2;k<=n;++k) if(k!=i)
            {
                int temp=query(1,i,k);
                if(temp>maxn) maxn=temp,j=k,sf2=1;
            }
            int k=1;
            for(;k<=n;++k) if(k!=2 && k!=i && k!=j) break;
            if(sf2) query(i,j,k)==maxn?print(i,j):print(2,i);
            else print(1,2);
            continue;
        }
        for(int k=2;k<=n;++k) if(k!=i)
        {
            int temp=query(1,i,k);
            if(temp>maxn) maxn=temp,j=k;
        }
        int k=1;
        for(;k<=n;++k) if(k!=2 && k!=i && k!=j) break;
        query(i,j,k)==maxn?print(i,j):print(2,i);
    }
    return 0;
}