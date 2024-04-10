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
random_device rd;
struct node{
	int data,size;
	unsigned int priority;
	struct node* child[2];
	node(int a){
		data=a;
		size=1;
		priority=rd();
		child[0]=NULL;
		child[1]=NULL;
	}
	int gtsz(int a){return (child[a]?child[a]->size:0);}
	void recalc(){size=1+gtsz(0)+gtsz(1);}
	node* rot(int a){
		node* temp=child[a];
		child[a]=child[a]->child[!a];
		temp->child[!a]=this;
		recalc(),temp->recalc();
		return temp;
	}
	node* insert(int a){
		int ch=(a>=data);
		if(!child[ch])child[ch]=new node(a);
		else child[ch]=child[ch]->insert(a);
		recalc();
		if(child[ch]->priority>priority)return rot(ch);
		return this;
	}
	bool count(int a){
		if(data==a)return true;
		int ch=(a>=data);
		if(child[ch])return child[ch]->count(a);
		return false;
	}
	int lower_bound(int a){
		int ch=(a>=data);
		if(ch)return gtsz(0)+1+(child[ch]?child[ch]->lower_bound(a):0);
		return (child[ch]?child[ch]->lower_bound(a):0);
	}
};
struct treap{
	node* rt;
	treap(){rt=NULL;}
	void insert(int a){rt=(rt?rt->insert(a):new node(a));}
	bool count(int a){return (rt?rt->count(a):0);}
	int lower_bound(int a){return (rt?rt->lower_bound(a):0);}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    pii points[n];
    for(int i=0;i<n;i++){
    	sc(points[i].first,points[i].second);
    }
    sort(points,points+n, [](const pii& lhs, const pii&rhs)->bool {
    	if(rhs.second==lhs.second)return lhs.first<rhs.first;
	    return rhs.second<lhs.second;
    });
    treap point;
    lli ans=0;
	for(int i=0;i<n;i++){
		int r=(i==n-1?1e9+1:(points[i+1].second==points[i].second?points[i+1].first:1e9+1));
		if(!point.count(points[i].first))point.insert(points[i].first);
		lli loptions=point.lower_bound(points[i].first-1)+1;
		lli roptions=point.lower_bound(r-1)-loptions+1;
		ans+=loptions*roptions;
	}
	prl(ans);
    return 0;
}