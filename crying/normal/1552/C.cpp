#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=310,MAXM=114514;
ll T,n,k,f[MAXN],a[MAXN],b[MAXN],num,ans;
vector<ll>v;
struct Trie{
    int ch[MAXM][2],cnt[MAXM],tot;
    il void clear(){tot=0;}
    il int node(){return cnt[++tot]=0,tot;}
    il void insert(int x){
        int u=0;
        per(i,16,0){
            if(!ch[u][(x>>i)&1])ch[u][(x>>i)&1]=node();
            u=ch[u][(x>>i)&1];cnt[u]++;
        }
    }
    il void del(int x){
        int u=0;
        per(i,16,0){u=ch[u][(x>>i)&1];cnt[u]--;}
    }
    il int query(int a,int b){
        int ret=0,u=0;
        per(i,16,0){
            if((b>>i)&1){
                ret+=cnt[ch[u][(a>>i)&1]];
            }
            u=ch[u][((a>>i)&1)^((b>>i)&1)];
            if(!u)break;
        }
        return ret+cnt[u];
    }
    
}trie;
il void read(ll& num){
	char ch;
	while((ch=getchar()) && (ch<'0' || ch>'9'));
	num=ch-'0';
	while((ch=getchar()) && (ch>='0' && ch<='9'))num=num*10+ch-'0'; 
}
void solve(){
	read(n);read(k);
	v.clear();num=ans=0;
	memset(f,0,sizeof f);
	rep(i,1,k){
		read(a[i]);read(b[i]);
	}
	rep(i,1,k){
		f[a[i]]|=1;
		f[b[i]]|=1;
	}
	rep(i,1,2*n){
		if(!f[i]){
			num++;
			v.pb(i);
		}
	}
	rep(i,0,num/2-1){
		a[k+i+1]=v[i];
		b[k+i+1]=v[i+num/2]; 
	} 
	rep(y,1,n){
		rep(x,1,y-1){
			ll A=a[x],B=b[x],C=a[y],D=b[y];
			if(B<A){swap(A,B);}
			if(D<C){swap(C,D);}
			if(!(A<C && C<B && A<D && D<B) && !((C>B||C<A) && (D>B||D<A)))ans++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	read(T);
	while(T--){
		solve();
	}

	return 0;
}