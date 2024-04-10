#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,i,j;
int query(int x){
	cout<<"? "<<x<<endl<<flush;
	cin>>x;return x;
}
void solve(int l,int r,int vl,int vr){
	if(r-l+1<=10){
		vector<int> v;
		v.push_back(123456);
		int i;
		for(i=l+1;i<r;i++){
			v.push_back(query(i));
		}
		v.push_back(123456);
		for(i=1;i+1<v.size();i++){
			if(v[i-1]>v[i]&&v[i+1]>v[i]){
				cout<<"! "<<i+l<<endl<<flush;
				return; 
			}
		}
		exit(-1); 
	}
	int a=l+(r-l)/3,b=r-(r-l)/3;
	int va=query(a),vb=query(b);
	if(va<vb){
		solve(l,b,vl,query(b));
	}
	else{
		solve(a,r,query(a),vr); 
	}
	/*if(va<vl){
		solve(l,a,vl,va);
		return;
	}
	if(va<vr){
		solve(a,r,va,vr);
		return;
	}
	if(vb<vl){
		solve(l,b,vl,vb);
		return;
	}
	if(vb<vr){
		solve(b,r,vb,vr);
		return;
	}*/
}
int main(){
	cin>>n;
	if(n==1){
		cout<<"! "<<1<<endl<<flush;
		return 0; 
	}
	solve(0,n+1,123456,123456);
	return 0;
}