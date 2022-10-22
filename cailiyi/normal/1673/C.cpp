#include<bits/stdc++.h>
#define N 40000
#define mod 1000000007
using namespace std;
int T,n,f[N+5];
vector<int> v;
inline void add(int &a,const int &b) {if((a+=b)>=mod) a-=mod;}
int main()
{
    scanf("%d",&T),f[0]=1;
    for(int i=1;i<=9;++i) v.emplace_back(i),v.emplace_back(i*11);
    for(int i=1;i<=9;++i) for(int j=0;j<=9;++j)
        v.emplace_back(i*101+j*10),v.emplace_back(i*1001+j*110);
    for(int i=1;i<=9;++i) for(int j=0;j<=9;++j) for(int k=0;k<=9;++k)
        v.emplace_back(i*10001+j*1010+k*100);
    for(int x:v) for(int i=x;i<=N;++i) add(f[i],f[i-x]);
    while(T--) scanf("%d",&n),printf("%d\n",f[n]);
    return 0;
}