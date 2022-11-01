//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,m,k,a[N],op[N],b[N],mx[N];
vector<pair<int,int> >ad[N];
vector<pair<double,int> >ml;
vector<int>ans;
inline bool comp(int x,int y){
	return op[x]<op[y];
}
signed main(){
	k=read();n=read();m=read();
	for(int i=1;i<=k;i++)a[i]=read();
	for(int i=1,u;i<=n;i++){
		op[i]=read();u=read();b[i]=read();
		if(op[i]==1){
			if(b[i]>b[mx[u]])mx[u]=i;
		}
		else if(op[i]==2){
			ad[u].push_back(make_pair(b[i],i));
		}
		else{
			ml.push_back(make_pair(b[i],i));
		}
	}
	for(int i=1;i<=k;i++){
		if(b[mx[i]]>a[i])ad[i].push_back(make_pair(b[mx[i]]-a[i],mx[i]));
		sort(ad[i].begin(),ad[i].end());
		for(int j=(signed)ad[i].size()-1,sum=a[i];j>=0;j--){
			ml.push_back(make_pair((double)(ad[i][j].first+sum)/sum,ad[i][j].second));
			sum+=ad[i][j].first;
		}
	}
	sort(ml.begin(),ml.end());
	for(int i=(signed)ml.size()-1;i>=0&&m--;i--)ans.push_back(ml[i].second);
	sort(ans.begin(),ans.end(),comp);
	cout<<ans.size()<<"\n";
	for(auto v:ans)cout<<v<<" "; 
	return (0-0);
}