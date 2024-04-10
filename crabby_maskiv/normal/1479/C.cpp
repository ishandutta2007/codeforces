#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=33;
int n,m;
int w[N];
struct edge{
	int u,v,w;
	inline edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge> ans;
int main(){
	int i,j;
	w[1]=1;
	ans.push_back(edge(1,0,1));
	w[2]=2;
	ans.push_back(edge(2,0,1));
	ans.push_back(edge(2,1,1));
	int L,R;cin>>L>>R;
	for(i=3;i<N;i++){
		w[i]=w[i-1]+w[i-2]+1;
		ans.push_back(edge(i,0,1));
		ans.push_back(edge(i,i-2,1));
		ans.push_back(edge(i,i-1,w[i-2]+1));
		if(w[i]>=(R-L+1)) break;
	}
	n=i+1;
	if(L==1){
		ans.push_back(edge(n,0,1));
		L++;
	}
	int x=R-L+1,c=L-1;
	for(i=n-1;i;i--){
		if(w[i]<=x){
			ans.push_back(edge(n,i,c));
			c+=w[i];
			x-=w[i];
		}
	}
	cout<<"YES"<<endl;
	n++;
	cout<<n<<" "<<ans.size()<<endl;
	for(auto e:ans){
		cout<<n-e.u<<" "<<n-e.v<<" "<<e.w<<endl;
	}
	return 0;
}