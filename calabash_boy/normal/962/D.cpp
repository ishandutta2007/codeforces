#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 15e4+100;
int n;
int a[maxn];
struct PQ_Node{
	int index;
	LL val;
	PQ_Node(){}
	PQ_Node(LL val_,int index_):val(val_),index(index_){}
	bool operator<(const PQ_Node &x)const{
		if (val==x.val){
			return index>x.index;
		}else{
			return val>x.val;
		}
	}
};
bool cmp(const PQ_Node& n1,const PQ_Node &n2){
	return n1.index<n2.index;
}
PQ_Node ans[maxn];
int tot=0;
priority_queue<PQ_Node> pq;
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		pq.push(PQ_Node(a[i],i));
	}
	while (pq.size()>=2){
		PQ_Node n1 = pq.top();
		pq.pop();
		PQ_Node n2 = pq.top();
		if (n1.val==n2.val){
			pq.pop();
			pq.push(PQ_Node(n1.val*2,max(n1.index,n2.index)));
		}else{
			ans[tot++] = PQ_Node(n1.val,n1.index);
		}
	}
	if (pq.size()==1){
		ans[tot++] = PQ_Node(pq.top().val,pq.top().index);
	}
	sort(ans,ans+tot,cmp);
	cout<<tot<<endl;
	for (int i=0;i<tot;i++){
		cout<<ans[i].val<<" ";
	}
	return 0;
}