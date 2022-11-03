#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
//#include <complex>
#include <set>

#define ll long long

using namespace std;

int bitCount(int x)
{
    int r=0;
    while(x)
    {
        r+=x&1;
        x>>=1;
    }
    return r;
}

bool get(ll n,ll k,ll a)
{
    if (k==0) return false;
    if (n&1)
    {
        if (a==n-1) return true;
        k--;
        n--;
    }
    if (k<=(n/2))
    {
        if (a%2==0) return false;
        if (a>=n-1-2*(k-1)) return true;
        else return false;
    }
    if (a&1) return true;
    k-=n/2;
    if (a>=n-2-2*(k-1)) return true;
    return false;
}
int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    ll n,k,q,a;
    cin >> n >> k >> q;
    for(int i=0;i<q;i++)
    {
        cin >> a;
        if (get(n,k,a-1)) printf("X");
        else printf(".");
    }
    printf("\n");
/*  for(k=1;k<=n;k++)
    {
        int best=-1,lpos=n+1;
        for(int mask=1;mask<(1<<n);mask++)
        {
            if (bitCount(mask)!=k) continue;
            int mp=0;
            for(int i=0;i<n;i++)
            {
                int nx=i,cnt=0;
                while((mask&(1<<nx))==0) nx=(nx+1)%n,cnt++;
                if (cnt%2==0) mp++;
            }
            if (mp<=lpos) best=mask,lpos=mp;
        }
        cout << k << "  ";
        for(int i=0;i<n;i++)
            if (best&(1<<i)) cout << "X";
            else cout << ".";
        cout << endl;
    }*/
    return 0;
}