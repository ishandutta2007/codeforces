#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=500005;
int t=1,n,a[N];

void solve()
{
    scanf("%d",&n);
    if(n<=3)
    {
        puts("-1");
        return;
    }
    if(n%2==0) printf("%d\n",n/4);
    else if(n%4==1) 
    {
        if(n<9) puts("-1");
        else printf("%d\n",(n-9)/4+1);
    }
    else if(n%4==3)
    {
        if(n<15) puts("-1");
        else printf("%d\n",(n-15)/4+2);
    }
}

int main()
{
    cin>>t;
    while(t--){solve();}
    return 0;
}