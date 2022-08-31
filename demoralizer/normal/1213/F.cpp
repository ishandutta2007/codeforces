#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define chrng(n,a,b)      (((n)>=(a))&&((n)<=(b)))
#define clamp(n,a,b)      (((n)<(a))?(a):((((n)>(b))?(b):(n)))

int p[200005];
int q[200005];
int pp[200005];
int qp[200005];
int alpha[200005];

int parent[200005];
int size[200005];
int findParent(int i)
{
	if(parent[parent[i]]!=parent[i])
		parent[i]=findParent(parent[i]);
	return parent[i];
}
void unionNodes(int a,int b)
{
	int parent_a=findParent(a),parent_b=findParent(b);
	if(parent_a==parent_b)
		return;
	if(size[parent_a]>=size[parent_b])
	{
		 size[parent_a]+=size[parent_b];
		 parent[parent_b]=parent_a;
	}
	else
	{
		 size[parent_b]+=size[parent_a];
		 parent[parent_a]=parent_b;
	}
	return;
}

void solve(){
	int n,k,t;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t;
		p[i]=t;
		pp[t]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>t;
		q[i]=t;
		qp[t]=i;
	}
	for(int i=1;i<=200002;i++){
		parent[i]=i;
		size[i]=1;
	}
	int i=1,j=qp[p[i]],pi=1,pj=1;
	while(i<=n){
		t=p[i];
		rep(z,pj,j+1){
			unionNodes(t,q[z]);
			i=max(i,pp[q[z]]);
		}
		pj=j;
		rep(z,pi,i+1){
			unionNodes(t,p[z]);
			j=max(j,qp[p[z]]);
		}
		if(pi==i)i++,pj++,j++;
		pi=i;
	}
	t=0;
	alpha[findParent(p[1])]=t;
	rep(i,2,n+1){
		if(findParent(p[i-1])!=findParent(p[i])){
			if(t+1<k)
				t++;
			alpha[findParent(p[i])]=t;
		}
	}
	if(t+1>=k){
		cout<<"YES\n";
		rep(i,1,n+1){
			cout<<(char)(alpha[findParent(i)]+'a');
		}
	}
	else cout<<"NO";
}
signed main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}