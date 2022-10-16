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
const int MAXN=1e5+10;
int T,n;
string s[MAXN];
char tmp[MAXN];
map<string,int>f;
void solve(){
    cin>>n;
    f.clear();
    rep(i,1,n){
        cin>>s[i];
        f[s[i]]=1;
    }
    rep(i,1,n){
        string t=s[i];
        reverse(t.begin(),t.end());
        if(f[t]==1){
            printf("YES\n");return;
        }
    }
    f.clear();
    rep(i,1,n){
        f[s[i]]=1;
        if(s[i].length()<=2)continue;
        tmp[0]=s[i][2];tmp[1]=s[i][1];tmp[2]='\0';
        if(f[tmp]==1){
            printf("YES\n");
            return;
        }
    }
    f.clear();
    per(i,n,1){
        f[s[i]]=1;
        if(s[i].length()<=2)continue;
        tmp[0]=s[i][1];tmp[1]=s[i][0];tmp[2]='\0';
        if(f[tmp]==1){
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}