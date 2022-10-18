#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n,l,w;
vector<int> lp,rp;

bool chk(long long i,long long j){
	if(j<i) return 0;
	long long f1=(j-i),f2=(i+j);
	if(f2==0) return (f1!=0);
	if(f2<0){
		return ((w*f1<(f2))||(w*f1>(-f2)));
	}else{
		return ((w*f1>(f2))||(w*f1<(-f2)));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>l>>w;
	while(n--){
		int x,v;
		cin>>x>>v;
		if(v==1)lp.push_back(x);
		else rp.push_back(x+l); 
	} 
	long long ans=0;
	int s=rp.size();
	sort(rp.begin(),rp.end(),less<int>());
	//for(int i=0;i<lp.size();i++){
	//	for(int j=0;j<rp.size();j++){
	//		cout<<lp[i]<<','<<rp[j]-l<<':'<<chk(lp[i],rp[j])<<endl;
	//	}
	//}
	for(int i=0;i<lp.size();i++){
		int l=0,r=s-1;
		while(r-l>2){
			int m=(l+r)/2;
			if(chk(lp[i],rp[m])){
				r=m;
			}else l=m;
		}
		int a=-1;
		for(int j=r;j>=l;j--){
			if(!chk(lp[i],rp[j])){
				a=j;
				break;
			} 
		} 
		ans+=s-a-1;
		//cout<<lp[i]<<':'<<ans<<endl;
	}
	
	cout<<ans;
	return 0;
}