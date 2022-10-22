#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,a[1000005],r[1000005];
char s[1000005];
vector<pii>fc[1000005];
set<pii>st;
ll ans;
vector<pii>v[1000005];
void add(int x,int p,int y){
	v[x].push_back({p,y}); 
	int cur=0;
	while(!v[x].empty()){
		cur+=v[x].back().se;
		if(cur<0){
			v[x].back().se=cur;
			break;
		}else v[x].pop_back();
	}
}
int got(int x){
	if(v[x].empty())return n;
	return v[x].back().fi-1;
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=1e6;i++){
		if(fc[i].empty()){
			fc[i].push_back({i,1});
			for(int j=i+i;j<=1e6;j+=i){
				int x=j,cnt=0;
				while(x%i==0)x/=i,cnt++;
				fc[j].push_back({i,cnt});
			}
			r[i]=n;
			st.insert({r[i],i}); 
		}
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%s",s+1);
	for(int i=n;i;i--){
		for(auto z:fc[a[i]]){
			int x=z.fi,y=z.se;
			if(s[i]!='*')y=-y;
			add(x,i,y);
			int R=r[x];
			r[x]=got(x);
			if(R!=r[x])st.erase({R,x}),st.insert({r[x],x});  
		}
		ans+=(*st.begin()).fi-i+1;
	}
	printf("%I64d",ans);
}