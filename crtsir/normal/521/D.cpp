#include<bits/stdc++.h>
using namespace std;
int k,n,m,t[100003],x[100003],b[100003],idx[100003],tag[100003];
bool cmp1(int X,int Y){
	if(t[X]!=t[Y])
		return t[X]<t[Y];
	return b[X]>b[Y];
}
bool cmp3(int X,int Y){
	if(tag[X]^tag[Y])return tag[X];
	if(t[X]!=t[Y])
		return t[X]<t[Y];
	return b[X]>b[Y];
}
long long a[100003];
struct number{
	long long x;
	long long y;
};
number val[100003];
bool cmp2(int X,int Y){
	return ((__int128)(val[X].x))*val[Y].y>((__int128)(val[Y].x))*val[X].y;
}
bool vis[100003];
int main(){
	cin>>k>>n>>m;
	for(int i=0;i<k;i++)
		scanf("%lld",a+i);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",t+i,x+i,b+i);x[i]--;
		idx[i]=i;
	}
	sort(idx,idx+n,cmp1);
	for(int i=0;i<n;i++)
		if(t[idx[i]]==1)
			if(vis[x[idx[i]]])
				b[idx[i]]=0;
			else
				t[idx[i]]=2,
				b[idx[i]]=b[idx[i]]-a[x[idx[i]]],
				vis[x[idx[i]]]=1,tag[idx[i]]=1;
	sort(idx,idx+n,cmp1);
	for(int i=0;i<n;i++){
		if(t[idx[i]]==1){
			val[idx[i]]=(number){b[idx[i]],a[x[idx[i]]]};
			if(a[x[idx[i]]]<b[idx[i]])a[x[idx[i]]]=b[idx[i]];
		}
		if(t[idx[i]]==2)
			val[idx[i]]=(number){b[idx[i]]+a[x[idx[i]]],a[x[idx[i]]]},
			a[x[idx[i]]]+=b[idx[i]];
		if(t[idx[i]]==3)
			val[idx[i]]=(number){b[idx[i]],1};
		idx[i]=i;
	}
	sort(idx,idx+n,cmp2);
	for(int i=0;i<m;i++)
		if(val[idx[i]].x<=val[idx[i]].y){
			m=i;
			break;
		}
	sort(idx,idx+m,cmp3);
	cout<<m<<endl;
	for(int i=0;i<m;i++)
		printf("%d ",idx[i]+1);
}