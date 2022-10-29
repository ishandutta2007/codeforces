#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
typedef pair<int,int> pii;
#define mk make_pair
const ll MOD=(ll)1e9+7;

void init()
{

}

ll n,m,f[N];
void solve()
{
    cin>>n>>m;
    f[1]=1; f[2]=2;
    for(int i=3;i<=max(n,m);i++) f[i]=(f[i-1]+f[i-2])%MOD;
    printf("%lld\n",(f[n]+f[m]-1+MOD)*2%MOD);
}

int main()
{
    int TTT=1; //scanf("%d",&TTT);
    while(TTT--){init(); solve();}
}