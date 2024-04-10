#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
int n;
void solve(int l,int r,int sum,int pre){
    if(l==r){
        printf("! %d\n",l);fflush(stdout);
        return;
    }
    int mid=((l+r)>>1)+1;
    if(mid%n==0){
        if(pre==r/n)solve(mid,r,sum,pre);
        else solve(l,mid-1,sum,pre);
        return;
    }
    int c=n-mid%n;
    printf("+ %d\n",c);fflush(stdout);
    int x;cin>>x;
    if(x==mid/n+1)solve(mid+c,r+c,sum+c,x);
    else solve(l+c,mid+c-1,sum+c,x);
}
int main(){
    cin>>n;
    solve(1,n-1,0,0);
    return 0;
}