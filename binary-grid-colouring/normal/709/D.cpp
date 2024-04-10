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
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)  
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N = 110; 
const int M=100010;
const int maxn=1001; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}

ll a00,a01,a10,a11;
int main()
{
	ll n,m;
    cin>>a00>>a01>>a10>>a11;
    n=(1+(int)( sqrt(1+8*a00) ))/2; //n:1 
    m=(1+(int)( sqrt(1+8*a11) ))/2; //m:0 
    if(a00==0&&a01==0&&a10==0&&a11==0){
    	cout<<0; return 0;
	}
    if(a01==0&&a10==0){
        if(a00==0) n=0;
        else m=0;
    }
    if(n*(n-1)!=2*a00||m*(m-1)!=2*a11||a01+a10!=n*m){
       cout<<"Impossible";
        return 0;
    }
    while(n+m){
        if(a01>=m){
           cout<<0;
            a01-=m;
            --n;
        }
        else{
            cout<<1;
            a10-=n;
            --m;
        }
    }
    return 0;
}