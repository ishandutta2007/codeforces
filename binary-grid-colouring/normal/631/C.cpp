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

int ans[N];
int num[N];
int ord[N];
int oper[N];
int main()
{
    int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;++i){
        scanf("%d",&num[i]);
    }
    int op,r;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&op,&r);
        oper[r]=op; ord[r]=i;
    }
    int F=1,R=n,nowop,now=0;
    for(int i=n;i>=1;--i)
	{
        if(!oper[i])
		{
            ans[i]=num[i];
        }
        else
		{
            R=i; break;
        }
    }
    sort(num+1,num+R+1);
    
    for(int i=R;i>=1;--i)
	{
        if(oper[i]&&ord[i]>now)
		{
            now=ord[i];
            nowop=oper[i];
        }
        if(nowop==1){ // 
            ans[i]=num[R--];
        }
        else {  // 
            ans[i]=num[F++];
        }
    }
    for(int i=1;i<=n;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}