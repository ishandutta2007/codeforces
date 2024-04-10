#include<iostream>
using namespace std;
const int o=1e5+10;
int st[o],tp,st2[o],tp2,E;string ans;
inline bool query(int l,int r){
	if(l>r) return false;
	string res;
	cout<<"? "<<r-l+1<<" ";
	for(;l<=r;++l) cout<<st[l]<<" ";
	cout<<endl;cin>>res;
	return res!="NO";
}
inline void push(int l,int r){for(;l<=r;++l) st2[++tp2]=st[l];}
inline void cpy(){
	tp=tp2;
	for(int i=1;i<=tp;++i) st[i]=st2[i];
}
int main(){
	cin>>E;
	for(int i=1,j=E;i<=j;++i) st[++tp]=i;
	for(;tp>2;cpy(),tp2=0){
		int l=1,r=tp,md1=l+(r-l)/3,md2=l+(r-l)*2/3;
		if(query(md2+1,r))
			if(query(md1+1,md2)) push(md1+1,r);
			else push(l,md1),push(md2+1,r);
		else if(query(md2+1,r))
			if(query(md1+1,md2)) push(md1+1,r);
			else push(l,md1),push(md2+1,r);
		else push(l,md2);
	}
	cout<<"! "<<st[1]<<endl;cin>>ans;
	if(ans!=":)") cout<<"! "<<st[2]<<endl;
	return 0;
}