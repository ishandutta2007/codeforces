#include<bits/stdc++.h>
using namespace std;
int idx[100003],a,b,c,d,n,x[100003],y[100003],X[100003],Y[100003],p[100003],_p[100003];
bool cmp1(int idx1,int idx2){
	return 1ll*a*x[idx2]-1ll*b*y[idx2]<1ll*a*x[idx1]-1ll*b*y[idx1];
}
bool cmp2(int idx1,int idx2){
	return 1ll*c*x[idx2]-1ll*d*y[idx2]>1ll*c*x[idx1]-1ll*d*y[idx1];
}
int dat[100003]; 
int query(int x){
	int ret=-114514;
	while(x){
		ret=max(ret,dat[x]);
		x-=(x&-x);
	}
	return ret;
}
void add(int x,int y){
	while(x<=100002){
		dat[x]=max(dat[x],y);
		x+=(x&-x);
	}
}
int main(){
	cin>>n;
	scanf("%d/%d %d/%d",&a,&b,&c,&d);
	for(int i=0;i<n;i++)
		scanf("%d%d",x+i,y+i),idx[i]=i;
	idx[n]=n; 
	sort(idx,idx+n+1,cmp1);
	for(int i=0,cnt=1;i<=n;i++){
		p[idx[i]]=cnt;
		if(cmp1(idx[i],idx[i+1]))
			cnt++;
	}
	sort(idx,idx+n+1,cmp2);
	int st=0;
	for(int i=0;i<=n;i++)
		if(idx[i]==n)
			st=i; 
	for(int i=0;i<100003;i++)dat[i]=-114514233;
	add(p[idx[st]],0);
	int i=st+1;
	while(i<=n&&!cmp2(idx[i-1],idx[i]))i++;
	for(int j;i<=n;i++){
		j=i;
		while(j<=n&&!cmp2(idx[i],idx[j]))j++;
		vector<int>v1,v2;
		for(int k=i;k<j;k++){
			v1.push_back(p[idx[k]]);
			v2.push_back(query(p[idx[k]]-1)+1);
		}
		for(int k=0;k<v1.size();k++)
			add(v1[k],v2[k]);
		i=j-1;
	}
	cout<<query(100001);
}