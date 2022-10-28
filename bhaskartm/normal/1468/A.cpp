#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pp pair<int,int>
#define fi first
#define se second
const int N=5e5+10;
int t_lp[4*N];
int lazy_lp[4*N];
int a[N];
int query_lp(int tn,int s,int e,int x,int y){
	if(s>=x && e<=y){
		return t_lp[tn];
	}
	if(e<x || s>y){
		return 0;
	}
	int mid=(s+e)/2;
	return max(query_lp(2*tn+1,s,mid,x,y),query_lp(2*tn+2,mid+1,e,x,y));
}
void update_lp(int tn,int s,int e,int x,int val){
	if(s==e){
		t_lp[tn]=val;
		return;
	}
	int mid=(s+e)/2;
	if(x>mid){
		update_lp(2*tn+2,mid+1,e,x,val);
	}else{
		update_lp(2*tn+1,s,mid,x,val);
	}
	t_lp[tn]=max(t_lp[2*tn+1],t_lp[2*tn+2]);
}
void build_lp(int tn,int s,int e){
	if(s==e){
		t_lp[tn]=0;
		return;
	}
	int mid=(s+e)/2;
	build_lp(2*tn+1,s,mid);
	build_lp(2*tn+2,mid+1,e);
	t_lp[tn]=max(t_lp[2*tn+1],t_lp[2*tn+2]);
}
int ans[N];
vector<int> gre[N];
stack<pp> s;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		build_lp(0,0,n-1);
		for(int i=0;i<n;i++){
			gre[i].clear();
		}
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i]--;
			bool an=true;
			while(s.size()&&s.top().fi<=a[i]){
				if(s.top().fi==a[i]){
					an=false;
				}
				s.pop();
			}
			if(s.size()&&an){
				gre[s.top().se].push_back(i);
			}
			s.push({a[i],i});
			ans[i]=0;
		}
		while(s.size()){
			s.pop();
		}
		for(int i=n-1;i>=0;i--){
			int temp=query_lp(0,0,n-1,a[i],n-1)+1;
			ans[a[i]]=temp;
			update_lp(0,0,n-1,a[i],temp);
			for(auto e:gre[i]){
				update_lp(0,0,n-1,a[e],ans[a[e]]+1);
				ans[a[e]]++;
			}
		}
		cout<<query_lp(0,0,n-1,0,n-1)<<endl;
	}
}