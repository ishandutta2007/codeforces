#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=200005;
//i_am_noob
int n,q,a[maxn],x,y,l,r,mid,k,pre,pre2,tmp;
string str;

struct segment_tree{
    vector<int> val,tag;
	int type;
	inline int mid(int l, int r){return l+r>>1;}
	segment_tree(int _siz, int _type){val.resize(4*_siz),tag.resize(4*_siz),type=_type;}
	inline int oper(int i, int j){
	    if(type==0) return i+j;
	    else if(type==1) return min(i,j);
	    else return max(i,j);
	}
	inline int def(){
	    if(type==0) return 0;
	    else if(type==1) return inf;
	    else return -inf;
	}
	void pull(int k){val[k]=oper(val[k<<1],val[(k<<1)+1]);}
	void push(int k, int l, int r){
		if(l!=r){
            if(type){
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=tag[k];
                val[(k<<1)+1]+=tag[k];
            }
			else{
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=(mid(l,r)-l+1)*tag[k];
                val[(k<<1)+1]+=(r-mid(l,r))*tag[k];
			}
		}
		tag[k]=0;
	}
	void modify(int k, int l, int r, int ql, int qr, int x){
		if(l>qr||r<ql) return;
		if(ql<=l&&qr>=r){
			if(type) val[k]+=x;
			else val[k]+=(r-l+1)*x;
			tag[k]+=x;
			return;
		}
		push(k,l,r);
		modify(k<<1,l,mid(l,r),ql,qr,x);
		modify((k<<1)+1,mid(l,r)+1,r,ql,qr,x);
		pull(k);
	}
	int query(int k, int l, int r, int ql, int qr){
		if(l>qr||r<ql) return def();
		if(ql<=l&&qr>=r) return val[k];
		push(k,l,r);
		return oper(query(k<<1,l,mid(l,r),ql,qr),query((k<<1)+1,mid(l,r)+1,r,ql,qr));
	}

};
segment_tree segtree1(maxn,2),segtree2(maxn,2),segtree3(maxn,2),segtree4(maxn,2),segtree5(maxn,2);

int first_true(segment_tree& tree1, segment_tree& tree2, function<bool(int,int)> f, int k, int l, int r, int ql, int qr, int cur1, int cur2, int de){
    if(k==1) if(!f(tree1.query(k,l,r,l,qr),tree2.query(k,l,r,l,qr))) return de;
    tree1.push(k,l,r),tree2.push(k,l,r);
    if(l==r) return l;
    if(tree1.mid(l,r)+1<=ql) return first_true(tree1,tree2,f,k<<1|1,tree1.mid(l,r)+1,r,ql,qr,tree1.oper(cur1,tree1.val[k<<1]),tree1.oper(cur2,tree2.val[k<<1]),de);
    if(tree1.mid(l,r)>=qr) return first_true(tree1,tree2,f,k<<1,l,tree1.mid(l,r),ql,qr,cur1,cur2,de);
    if(f(tree1.oper(cur1,tree1.val[k<<1]),tree1.oper(cur2,tree2.val[k<<1]))) return first_true(tree1,tree2,f,k<<1,l,tree1.mid(l,r),ql,qr,cur1,cur2,de);
    else return first_true(tree1,tree2,f,k<<1|1,tree1.mid(l,r)+1,r,ql,qr,tree1.oper(cur1,tree1.val[k<<1]),tree1.oper(cur2,tree2.val[k<<1]),de);
}

int first_true(segment_tree& tree1, segment_tree& tree2, function<bool(int,int)> f, int ql, int qr, int de){return first_true(tree1,tree2,f,1,1,2*n-1,ql,qr,tree1.def(),tree2.def(),de);}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q >> str;
    a[0]=0;
    rep(sz(str)) a[i+1]=a[i]+(str[i]=='('?1:-1);
    rep(2*n-1){
        segtree1.modify(1,1,2*n-1,i+1,i+1,a[i]);
        segtree2.modify(1,1,2*n-1,i+1,i+1,a[i]);
        segtree4.modify(1,1,2*n-1,2*n-1-i,2*n-1-i,a[i]);
        segtree5.modify(1,1,2*n-1,2*n-1-i,2*n-1-i,a[i]);
    }
    rep(2*n-1) segtree3.modify(1,1,2*n-1,i+1,i+1,segtree1.query(1,1,2*n-1,1,i+1)+segtree1.query(1,1,2*n-1,i+1,2*n-1)-2*a[i]);
    //rep(2*n-1) print0(segtree1.query(1,1,2*n-1,i+1,i+1));
    //cout << "\n";
    //rep(2*n-1) print0(segtree3.query(1,1,2*n-1,i+1,i+1));
    //cout << "\n";
    print1(segtree3.query(1,1,2*n-1,1,2*n-1));
    //print1("noob");
    while(q--){
        cin >> x >> y;
        if(x>y) swap(x,y);
        if(str[x-1]==str[y-1]){
            print1(segtree3.query(1,1,2*n-1,1,2*n-1));
            continue;
        }
        if(str[x-1]==')'){
            swap(str[x-1],str[y-1]);
            segtree2.modify(1,1,2*n-1,x+1,y,2);
            segtree5.modify(1,1,2*n-1,2*n-y,2*n-1-x,2);
            segtree3.modify(1,1,2*n-1,x+1,y,-4);
            rep(2){
                l=first_true(segtree1,segtree2,[&](int tmp1, int tmp2){return tmp2>=tmp1+1+i;},x+1,y,y+1);
                segtree3.modify(1,1,2*n-1,l,y,1);

                l=first_true(segtree1,segtree2,[&](int tmp1, int tmp2){return tmp2<tmp1+1+i;},y+1,2*n-1,2*n)-1;
                segtree3.modify(1,1,2*n-1,y+1,l,1);

                l=2*n-first_true(segtree4,segtree5,[&](int tmp1, int tmp2){return tmp2>=tmp1+1+i;},2*n-y,2*n-x-1,2*n-x);
                segtree3.modify(1,1,2*n-1,x+1,l,1);

                l=2*n-first_true(segtree4,segtree5,[&](int tmp1, int tmp2){return tmp2<tmp1+1+i;},2*n-x,2*n-1,2*n)+1;
                segtree3.modify(1,1,2*n-1,l,x,1);
            }
            segtree1.modify(1,1,2*n-1,x+1,y,2);
            segtree4.modify(1,1,2*n-1,2*n-y,2*n-1-x,2);
        }
        else{
            swap(str[x-1],str[y-1]);
            segtree2.modify(1,1,2*n-1,x+1,y,-2);
            segtree5.modify(1,1,2*n-1,2*n-y,2*n-1-x,-2);
            segtree3.modify(1,1,2*n-1,x+1,y,4);
            rep(2){
                l=first_true(segtree1,segtree2,[&](int tmp1, int tmp2){return tmp2<=tmp1-1-i;},x+1,y,y+1);
                segtree3.modify(1,1,2*n-1,l,y,-1);

                l=first_true(segtree1,segtree2,[&](int tmp1, int tmp2){return tmp2>tmp1-1-i;},y+1,2*n-1,2*n)-1;
                segtree3.modify(1,1,2*n-1,y+1,l,-1);

                l=2*n-first_true(segtree4,segtree5,[&](int tmp1, int tmp2){return tmp2<=tmp1-1-i;},2*n-y,2*n-x-1,2*n-x);
                segtree3.modify(1,1,2*n-1,x+1,l,-1);

                l=2*n-first_true(segtree4,segtree5,[&](int tmp1, int tmp2){return tmp2>tmp1-1-i;},2*n-x,2*n-1,2*n)+1;
                segtree3.modify(1,1,2*n-1,l,x,-1);
            }
            segtree1.modify(1,1,2*n-1,x+1,y,-2);
            segtree4.modify(1,1,2*n-1,2*n-y,2*n-1-x,-2);
        }
        //rep(2*n-1) print0(segtree1.query(1,1,2*n-1,i+1,i+1));
        //cout << "\n";
        //rep(2*n-1) print0(segtree3.query(1,1,2*n-1,i+1,i+1));
        //cout << "\n";
        print1(segtree3.query(1,1,2*n-1,1,2*n-1));
    }
    return 0;
}