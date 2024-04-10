#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;
const int maxm=1000005;

int n;
int dc[maxm];
long long bit[maxn];
set<int> st;
int a[maxn];

inline int lbt(int x){return x&(-x);}
inline void chg(int i,int v){
	while(i<maxn){bit[i]+=v;i+=lbt(i);}
}
inline long long qry(int i){
	long long ans=0;while(i){ans+=bit[i];i-=lbt(i);}
	return ans;
}

int main(){
	for(int i=1;i<maxm;i++){
		for(int j=i;j<maxm;j+=i)dc[j]++;
	}
	int q;
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>2) st.insert(i);
		chg(i,a[i]);
	}
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t==1){
			set<int>::iterator itl=st.lower_bound(x),itr=st.upper_bound(y);
			vector<int> del;
			for(set<int>::iterator it=itl;it!=itr;it++){
				int g=a[*it];a[*it]=dc[g];
				chg(*it,-g);
				chg(*it,dc[g]);
				if(dc[g]<=2)del.push_back(*it);
			}
			for(int i=0;i<del.size();i++) st.erase(del[i]);
		}else{
			cout<<qry(y)-qry(x-1)<<'\n';
		}
	}
	return 0;
}