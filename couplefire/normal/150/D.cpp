#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include<complex>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
const int N = 151 , inf = 1<<30;
int f[N][N][77] , a[N] , n;
char s[N];
int solve(int l,int r,int c){
    if(l>r) return c?-inf:0;
    if(~f[l][r][c]) return f[l][r][c];
    int &ret = f[l][r][c];
    if(c == 76){
        ret = max(0 , solve(l,r,0));
        rep(i,l,r) ret = max(ret , solve(l,i,c) + solve(i+1,r,c));
    } else {
        ret = -inf;
        if(s[l] == s[r]){
            ret = max(ret , solve(l+1,r-1,c+1));
            ret = max(ret , solve(l+1,r-1,0)+a[c*2+2-(l==r)]);
        }
        rep(i,l,r) ret = max(ret , solve(l,i,0) + solve(i+1,r,c));
        rep(i,l,r) ret = max(ret , solve(l,i,c) + solve(i+1,r,0));
    }
    return ret;
}
 
int main(){
    memset(f,-1,sizeof(f));
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",a + i) , (a[i] == -1) && (a[i] = -inf);
    scanf("%s",s+1);
    printf("%d\n",solve(1,n,76));
    return 0;
}