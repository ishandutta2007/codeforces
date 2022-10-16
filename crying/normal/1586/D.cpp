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
const int MAXN=110;
int n,p[MAXN];
void qwq(int num){
	printf("%d\n",num);fflush(stdout);
}
int main(){
	cin>>n;
	int flag=0;
    rep(i,1,n){
    	printf("? ");
        rep(j,1,n-1)printf("1 ");
        qwq(n-i+1);
        int k;scanf("%d",&k);
        if(k!=0){p[n]=i;flag=1;break;}
    }
    if(!flag)p[n]=n;
    rep(i,1,n){
        if(i==p[n])continue;
        if(i>p[n]){printf("? ");
            rep(j,1,n-1)printf("1 ");
            qwq(i-p[n]+1);
            int k;scanf("%d",&k);p[k]=i;
        }
        else{
            printf("? ");
            rep(j,1,n-1)printf("%d ",p[n]-i+1);
            qwq(1);
            int k;scanf("%d",&k);p[k]=i;
        }
    }
    printf("! ");rep(i,1,n)printf("%d ",p[i]);printf(" ");fflush(stdout);

	return 0;
}