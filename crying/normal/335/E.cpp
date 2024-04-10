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
typedef long double db;
using namespace std;
const int MAXN=3e4+10;
string s;
int n,h;
db ans;
int P(int x){return (1<<x);}
int main(){
    cin>>s>>n>>h;
    if(s[0]=='B')return printf("%d",n),0;
    ans=n;
    rep(i,1,h){
        //i
        rep(j,1,n-1){
            //j
            db ret=(n-j); //ret
            ret=ret*pow((db)1-1.00/P(i),j-1)*pow((db)1.00/P(i),2);
            ret=ret*(P(i)-P(i-1)*(1+(j-1)*((db)1.00/(P(i)-1))));
            ans+=ret;
        }
    }
    printf("%.9Lf",ans);
    return 0;
}