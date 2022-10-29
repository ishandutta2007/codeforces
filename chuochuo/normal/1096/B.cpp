#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
void inc(int &a) {a++; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    cin>>str;
    char ch=str[0];
    int ans=1;
    for(int i=1;i<n;i++) 
    {
        if(str[i]!=ch) break;
        inc(ans);
    }
    inc(ans);
    ch=str[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(str[i]!=ch) break;
        inc(ans);
    }
    if(str[0]==str[n-1])
    {
        ch=str[0];
        int l=1,r=n-2;
        while(str[r]==ch) r--;
        while(str[l]==ch) l++;
        ans=1LL*(l+1)*(n-r)%MOD;
    }
    else inc(ans);
    printf("%d\n",ans);
    return 0;
}