#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli arr[(int)2e5+1];
struct node{
	lli data,lazy;
	int le,ri;
	struct node* left;
	struct node* right;
	node(){
		data=0;
		lazy=-1;
		le=0;
		ri=0;
		left=NULL;
		right=NULL;
	}
	int mid(){
		return (le+ri)/2;
	}
	void mt(int l, int r){
		le=l;
		ri=r;
		if(le!=ri){
			left=new node();
			right= new node();
			left->mt(le,mid());
			right->mt(mid()+1,ri);
		}
		else{
			data=arr[le];
		}
	}
	void resolvelazy(){
		data=max(data,lazy);
		if(left){
			left->lazy=max(left->lazy,lazy);
			right->lazy=max(right->lazy,lazy);
		}
		lazy=-1;
	}
	void update(int l, int r,lli am){
		if(lazy!=-1)resolvelazy();
		if(le>r||ri<l)return;
		if(le>=l&&ri<=r){
			lazy=am;
			resolvelazy();
			return;
		}
		left->update(l,r,am);
		right->update(l,r,am);
	}
	void update2(int loc, lli am){
		if(lazy!=-1)resolvelazy();
		if(le==ri){
			data=am;
			return;
		}
		if(loc<=mid())left->update2(loc,am);
		else right->update2(loc,am);
	}
	void print(){
		if(lazy!=-1)resolvelazy();
		if(le!=ri){
			left->print();
			right->print();
		}
		else{
			printf("%lli ",data);
		}
	}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	node tree;
	tree.mt(1,n);
	int q;
	cin>>q;
	int a,b;
	lli c;
	for(int i=0;i<q;i++){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			tree.update2(b,c);
		}
		else{
			cin>>c;
			tree.update(1,n,c);
		}
	}
	tree.print();
	return 0;
}