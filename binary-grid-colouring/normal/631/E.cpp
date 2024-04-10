#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson  l , mid , rt << 1  
#define rson  mid + 1 , r , rt << 1 | 1  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9+7;  
const ll mod = (1LL<<32);
const int N =2e5+7; 
const int M=100010;
const ll MAX=1e18;
//const int maxn=1001; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
ll a[N],cur;
ll w1,w2,sum[N],val;
int n,mid1,mid2;
int Left,Right;

ll calc(int x,int y)
{
    if(x<=y)return val-sum[y]+sum[x]+a[x]*(y-x);
    else return val+sum[x-1]-sum[y-1]+a[x]*(y-x);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        val += i*a[i];
    }
    ll ans=-inf;
    for(int i=1;i<=n;i++)
    {
        Left=1;Right=n;
		cur=-inf;
        while(Left+1<=Right)
        {
            mid1=Left+(Right-Left)/3;
            mid2=Right-(Right-Left)/3;
            w1=calc(i,mid1);
            w2=calc(i,mid2);
            if(w1>w2)
			{
			  	Right=mid2-1;
			  	cur=max(cur,w1);}
            else 
			{
				Left=mid1+1;
				cur=max(cur,w2);
			}
        }
        cur=max(cur,calc(i,Left));
        if(cur>ans)ans=cur;
    }
    cout<<ans;
    return 0;
}