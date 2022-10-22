#include <iostream>

using namespace std;
int p, q, notprime[10000000], pal[10000000];
long long kpr[10000000], kpal[10000000];
long long pal1(long long i)
{
    long long ans=i;
    while(i!=0)
    {
        ans=ans*10+i%10;
        i=i/10;
    }
    return ans;
}
long long pal2(long long i)
{
    long long ans=i;
    i=i/10;
    while(i!=0)
    {
        ans=ans*10+i%10;
        i=i/10;
    }
    return ans;
}

int main()
{
    cin >> p >> q;
    for(int i=2;i<5000;i++)
        for(int j=i*i;j<10000000;j+=i)
        notprime[j]=1;
    notprime[1]=1;
    for(int i=1;i<10000;i++)
    {
        if(pal1(i)<10000000)
            pal[pal1(i)]=1;
        if(pal2(i)<10000000)
            pal[pal2(i)]=1;
    }
    for(int i=1;i<10000000;i++)
    {
        kpr[i]=kpr[i-1];
        kpal[i]=kpal[i-1];
        if(notprime[i]==0)
            kpr[i]++;
        if(pal[i]==1)
            kpal[i]++;
    }
    int i=9999999;
    while(i>=1 && kpr[i]*q>kpal[i]*p)
    {
        i--;
    }
    cout << i;
    return 0;
}