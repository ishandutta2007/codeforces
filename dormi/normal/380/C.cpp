#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e6+1;
int arr[MAXN];
struct data{
	int longest;
	int am[2];
	data(){
		longest=0;
		am[0]=0;
		am[1]=0;
	}
};
data combine(data a, data b){
	data te;
	int added=min(a.am[0],b.am[1]);
	te.longest=a.longest+b.longest+2*added;
	te.am[0]=a.am[0]+b.am[0]-added;
	te.am[1]=a.am[1]+b.am[1]-added;
	return te;
}
struct node{
	data am;
	int le,ri;
	struct node* left;
	struct node* right;
	node(){
		am=data();
		le=0,ri=0;
		left=NULL;
		right=NULL;
	}
	int mid(){return (le+ri)/2;}
	void mt(int l, int r){
		le=l,ri=r;
		if(le!=ri){
			left=new node();
			right=new node();
			left->mt(l,mid());
			right->mt(mid()+1,r);
			am=combine(left->am,right->am);
		}
		else{
			am.am[arr[le]]=1;
		}
	}
	void update(int loc){
		if(loc>ri||loc<le)return;
		if(le==ri){
			am.am[!arr[loc]]=0,am.am[arr[loc]]=1;
			return;
		}
		left->update(loc),right->update(loc);
		am=combine(left->am,right->am);
	}
	data query(int l, int r){
		if(l>ri||r<le)return data();
		if(le>=l&&ri<=r)return am;
		return combine(left->query(l,r),right->query(l,r));
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string in;
    sc(in);
	rep(i,0,sz(in)){
		arr[i+1]=(in[i]==')'?1:0);
	}
	int q;
	sc(q);
	int a,b;
	node tree;
	tree.mt(1,sz(in));
	while(q--){
		sc(a,b);
		prl(tree.query(a,b).longest);
	}
    return 0;
}