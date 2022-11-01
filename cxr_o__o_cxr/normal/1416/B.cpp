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
const int N=10004;
int n,ave,fl,a[N];
struct node{
	int x,y,w;
};
vector<node>ans;
vector<pair<int,int> >vec; 
signed main(){
	for(int T=read();T--;){
		n=read();
		ave=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			ave+=a[i];
		}
		if(ave%n){puts("-1");continue;}
		ave/=n;
		ans.clear();
		vec.clear();
		for(int i=2;i<=n;i++){
			if(a[i]/i)ans.push_back((node){i,1,a[i]/i});
			a[1]+=a[i]/i*i;
			a[i]%=i;
			if(a[i])vec.push_back(make_pair(i-a[i],i));
		}
		sort(vec.begin(),vec.end());
		for(auto v:vec){
			if(a[1]>=n||v.first>a[1])break;
			ans.push_back((node){1,v.second,v.first});
			ans.push_back((node){v.second,1,1});
			a[1]+=a[v.second];
			a[v.second]=0;
		}
		vec.clear();
		for(int i=2;i<=n;i++)if(a[i]>ave){
			vec.push_back(make_pair(i+ave-a[i],i));
		}
		sort(vec.begin(),vec.end());
		fl=1;
		for(auto v:vec){
			if(v.first>a[1]){
				fl=0;
				break;
			}
			ans.push_back((node){1,v.second,v.first});
			ans.push_back((node){v.second,1,1});
			a[1]+=v.second-v.first;
		}
		if(!fl){
			puts("-1");
			continue;
		}
		for(int i=2;i<=n;i++)if(a[i]<ave){
			ans.push_back((node){1,i,ave-a[i]});
		}
		cout<<ans.size()<<"\n";
		for(auto v:ans){
			cout<<v.x<<" "<<v.y<<" "<<v.w<<"\n";
		}
	} 
	return (0-0);
}