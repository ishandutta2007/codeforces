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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int arr[(int)1e5+1];
struct node{
	bitset<26> data;
	int le,ri;
	struct node* left;
	struct node* right;
	node(){
		le=0;
		ri=0;
		data=0;
		left=NULL;
		right=NULL;
	}
	int mid(){return (le+ri)/2;}
	void mt(int l, int r){
		le=l,ri=r;
		if(le!=ri){
			left= new node();
			right= new node();
			left->mt(le,mid());
			right->mt(mid()+1,ri);
			data=left->data|right->data;
		}
		else{
			data[arr[le]]=true;
		}
	}
	void update(int loc){
		if(le==ri){
			data=0;
			data[arr[loc]]=true;
			return;
		}
		if(loc<=mid())left->update(loc);
		else right->update(loc);
		data=left->data|right->data;
	}
	bitset<26> query(int l, int r){
		if(ri<l||le>r)return 0;
		if(le>=l&&ri<=r){
			return data;
		}
		return left->query(l,r)|right->query(l,r);
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	string a;
	sc(a);
	int n=a.size();
	rep(i,0,n){
		arr[i+1]=a[i]-'a';
	}
	node tree;
	tree.mt(1,n);
	int q;
	sc(q);
	int in,l,r;
	char b;
	while(q--){
		sc(in,l);
		if(in==1){
			sc(b);
			r=b-'a';
			arr[l]=r;
			tree.update(l);
		}
		else{
			sc(r);
			prl(tree.query(l,r).count());
		}
	}
    return 0;
}