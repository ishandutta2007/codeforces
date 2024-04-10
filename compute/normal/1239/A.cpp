#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const int mod=1e9+7;
long long fib[maxn];
void db()
{
    fib[0]=fib[1]=1;
    for(int i=2;i<maxn;i++) fib[i]=(fib[i-1]+fib[i-2])%mod;
}
int main()
{
    db();
    int n,m;
    cin>>n>>m;
    cout<<(fib[n]+fib[m]-1)*2%mod<<endl;
}