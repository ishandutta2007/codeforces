#include<bits/stdc++.h>
using namespace std;
int n,m,a[153],b[153],d[153],idx[153];
bool cmp(int x,int y){
	return d[x]<d[y];
}
bitset<150>tmp;
struct mat{
	vector<bitset<150> >v;
	void init(int n){
		for(int i=0;i<n;i++)
			v.push_back(tmp);
	}
	void b1(){
		for(int i=0;i<150;i++)
			v[i][i]=1;
	}
};
mat mul(mat x,mat y){
	mat ret;
	ret.init(x.v.size());
	for(int i=0;i<x.v.size();i++)
		for(int j=0;j<150;j++)
			if(x.v[i][j])
				ret.v[i]|=y.v[j];
	return ret;
}
mat mypow(mat x,int times){
	mat ret;
	ret.init(x.v.size());
	ret.b1();
	while(times){
		if(times&1)
			ret=mul(ret,x);
		x=mul(x,x);times>>=1;
	}return ret;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",a+i,b+i,d+i);
		a[i]--;b[i]--;idx[i]=i;
	}
	sort(idx,idx+m,cmp);
	mat nw,ch,tmp;
	nw.init(1);
	ch.init(150);
	nw.v[0][0]=1;
	int ans=1100000000,lst=0;
	for(int i=0;i<m;i++){
		nw=mul(nw,mypow(ch,d[idx[i]]-lst));
		ch.v[a[idx[i]]][b[idx[i]]]=1;
		tmp=nw;
		for(int j=0;j<n;j++){
			if(tmp.v[0][n-1]){
				ans=min(ans,d[idx[i]]+j);
				break;
			}
			tmp=mul(tmp,ch);
		}lst=d[idx[i]];
	}
	if(ans==1100000000)
		cout<<"Impossible";
	else
		cout<<ans;
}