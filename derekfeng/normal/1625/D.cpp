#include<bits/stdc++.h>
using namespace std;
int n,k,tot=1,a[300004];
map<int,vector<int> >mp;
vector<int>num;
int s[2][9000000],dat[9000000];
void ins(int u,int d,int x,int p){
	dat[u]=p;
	if(d<0)return;
	int t=(x>>d)&1;
	if(s[t][u]==0){
		s[t][u]=++tot;
		s[0][tot]=s[1][tot]=dat[tot]=0;
	}
	ins(s[t][u],d-1,x,p);
}
int fnd(int u,int d,int x){
	if(u==0)return -1;
	if(d<0)return dat[u];
	int t=(x>>d)&1,T=(k>>d)&1;
	if(T==0&&s[t^1][u]!=0)return dat[s[t^1][u]];
	return fnd(s[t^T][u],d-1,x);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(k==0){
		printf("%d\n",n);
		for(int i=1;i<=n;i++)printf("%d ",i);
		return 0;
	}
	int pos;
	for(int i=30;~i;i--)if((k>>i)&1){pos=i;break;}
	for(int i=1;i<=n;i++)mp[a[i]>>(pos+1)].push_back(i);
	for(auto it=mp.begin();it!=mp.end();it++){
		vector<int>v[2];
		for(auto x:(it->second))
			v[(a[x]>>pos)&1].push_back(x);
		tot=1,s[0][1]=s[1][1]=dat[1]=0;
		for(auto x:v[0])ins(1,30,a[x],x);
		bool ok=0;
		for(auto x:v[1]){
			int tmp=fnd(1,30,a[x]);
			if(tmp!=-1){
				num.push_back(x),num.push_back(tmp);
				ok=1;break;
			}
		}
		if(!ok){
			if(v[0].size())num.push_back(v[0][0]);
			else num.push_back(v[1][0]);
		}
	}
	sort(num.begin(),num.end());
	if(num.size()<2)puts("-1");
	else{
		printf("%d\n",num.size());
		for(auto x:num)printf("%d ",x);
	}
}