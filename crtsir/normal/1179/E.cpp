#include<bits/stdc++.h>
using namespace std;
const long long maxn=1000000000000000000;
mt19937 rng(time(0));
long long L,al[1003],ar[1003],LL,RR;
long long query(int i,long long p){
	cout<<"? "<<i+1<<' '<<p<<endl;
	cin>>p;
	return p;
}
long long findval(int i,long long val){
	long long l=LL,r=RR,mid;
	while(l!=r){
		mid=(l+r>>1);
		if(query(i,mid)<val)
			l=mid+1;
		else
			r=mid;
	}return l;
}
void merge(vector<int>&x,vector<int>&y){
	while(y.size())
		x.push_back(y.back()),y.pop_back();
}
void split(vector<int>v,long long val,vector<int>&l,vector<int>&r,int szl,int szr,long long &tmp){
	int i=rng()%v.size();
	long long p=findval(v[i],val);
	vector<int>g[3];
	for(int i=0;i<v.size();i++){
		long long t=query(v[i],p);
		g[(t<val)+(t<=val)].push_back(v[i]);
	}
	if(g[0].size()+l.size()>szl){
		merge(r,g[1]);
		merge(r,g[2]);
		split(g[0],val,l,r,szl,szr,tmp);
		return;
	}
	if(g[2].size()+r.size()>szr){
		merge(l,g[0]);
		merge(l,g[1]);
		split(g[2],val,l,r,szl,szr,tmp);
		return;
	}
	tmp=p;
	merge(l,g[0]);
	merge(r,g[2]);
	while(l.size()<szl)l.push_back(g[1].back()),g[1].pop_back();
	while(r.size()<szr)r.push_back(g[1].back()),g[1].pop_back();
}
void calc(vector<int>v,long long l,long long r,int _l,int _r){
	LL=l;RR=r;
	if(v.size()==1){
		al[v[0]]=l,ar[v[0]]=r;
		return;
	}
	vector<int>_L,_R;long long mid;
	split(v,(_l+_r>>1)*L,_L,_R,(_r-_l>>1),(_r-_l+1>>1),mid);
	calc(_L,l,mid,_l,_l+_r>>1);
	calc(_R,mid,r,_l+_r>>1,_r);
}
int main(){
	int n;
	cin>>n>>L;L/=n;
	vector<int>v;
	for(int i=0;i<n;i++)
		v.push_back(i);
	calc(v,0,maxn,0,n);
	cout<<"!\n";
	for(int i=0;i<n;i++)
		cout<<al[i]<<' '<<ar[i]<<endl; 
}