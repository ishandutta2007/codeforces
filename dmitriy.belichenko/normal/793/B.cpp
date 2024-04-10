#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<numeric>
using namespace std;
#define PI acos(-1.0)
#define LL __int64
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define mm(a,b) memset(a,b,sizeof(a))
#define PP puts("*********************");
template<class T> T f_abs(T a){ return a > 0 ? a : -a; }
template<class T> T gcd(T a, T b){ return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
// 0x3f3f3f3f3f3f3f3f
// 0x3f3f3f3f

const int maxn=1005;
char mp[maxn][maxn];
int n,m,sr,sc,er,ec;
int judge_col(int L,int R,int j){//
    if(L>R) swap(L,R);
    for(int i=L;i<=R;i++)
        if(mp[i][j]=='*')
            return 0;
    return 1;
}
int judge_row(int i,int L,int R){//
    if(L>R) swap(L,R);
    for(int j=L;j<=R;j++)
        if(mp[i][j]=='*')
            return 0;
    return 1;
}
int solve(){
    for(int j=0;j<m;j++){
        if(judge_col(sr,er,j)&&judge_row(sr,sc,j)&&judge_row(er,ec,j))
            return 1;
    }
    for(int i=0;i<n;i++){
        if(judge_row(i,sc,ec)&&judge_col(i,sr,sc)&&judge_col(i,er,ec))
            return 1;
    }
    return 0;
}
int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(mp[i][j]=='S')
                sr=i,sc=j;
            else if(mp[i][j]=='T')
                er=i,ec=j;
        }
    if(solve()) printf("YES\n");
    else printf("NO\n");
    return 0;
}