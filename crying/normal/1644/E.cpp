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
const int MAXN=2e5+100;
ll T,n,m;
array<int,2>suf[MAXN];
char s[MAXN];
ll raw[MAXN*2],tot;
struct L{
	ll xa,xb,y,v;	
	bool operator<(const L& l2)const{
		if(y!=l2.y)return y<l2.y;
		return v>l2.v; // 
	}
}l[MAXN*2];
ll ans,cnt;
struct SegTree{
	ll len[MAXN<<4],tag[MAXN<<4];
    void clear(int x,int l,int r){
        len[x]=tag[x]=0;
        if(l==r){
            len[lc(x)]=len[rc(x)]=tag[lc(x)]=tag[rc(x)]=0;
            return;
        }
        int mid=(l+r)>>1;
        clear(lc(x),l,mid);clear(rc(x),mid+1,r);
    }
	void pushup(int x,int l,int r){
		if(tag[x])len[x]=raw[r+1]-raw[l];
		else len[x]=len[lc(x)]+len[rc(x)];
	}	
	void upd(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l && qr>=r){
			tag[x]+=val;
			pushup(x,l,r);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid)upd(lc(x),l,mid,ql,qr,val);
		if(qr>mid)upd(rc(x),mid+1,r,ql,qr,val);
		pushup(x,l,r);
	}
}t;
void add(int a,int b,int c,int d){
    if(a>c)swap(a,c);
    if(b>d)swap(b,d);
    cnt++;
	l[cnt*2-1]=(L){a,c,b,1};
	l[cnt*2]=(L){a,c,d,-1};
	raw[++tot]=a;
	raw[++tot]=c;
}
void solve(){
    cin>>n>>(s+1);
    m=strlen(s+1);
    ans=tot=cnt=0;
    suf[m+1]={0,0};
    per(i,m,1){
        suf[i]=suf[i+1];
        if(s[i]=='R')suf[i][0]++;
        else suf[i][1]++;
    }
    add(1,0,0,1);
    int x=1,y=1;
    rep(i,1,m){
        if(s[i]=='R')y++;
        else x++;
        if(x==1){
            int rest=(n-y-suf[i+1][0]);
            add(1,y-1,0,y+rest);
        }else if(y==1){
            int rest=(n-x-suf[i+1][1]);
            add(x+rest,0,x-1,1);
        }else{
            int restx=(n-x-suf[i+1][1]),resty=(n-y-suf[i+1][0]);
            add(x+restx,y-1,x-1,y+resty);
        }
    }
	sort(raw+1,raw+1+tot);
	sort(l+1,l+1+2*cnt);
	tot=unique(raw+1,raw+1+tot)-raw-1;
	rep(i,1,cnt*2){
		l[i].xa=lower_bound(raw+1,raw+1+tot,l[i].xa)-raw;
		l[i].xb=lower_bound(raw+1,raw+1+tot,l[i].xb)-raw;
    }
	rep(i,1,cnt*2-1){
		t.upd(1,1,tot-1,l[i].xa,l[i].xb-1,l[i].v);
		ans+=t.len[1]*(l[i+1].y-l[i].y);
	}
    t.clear(1,1,tot-1);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        solve();
    }

	return 0;
}