#include<bits/stdc++.h>
using namespace std;
int K,q;
string s;
int typ[300000],num[300000],d[300000];
int t(char c){
	if(c=='1')return 1; 
	if(c=='0')return 0;
	if(c=='?')return 2;
}
void built(int id,int dep){
	d[id]=dep,typ[id]=t(s[id]);
	if(dep==0){
		num[id]=(typ[id]==2)+1;
		return;
	}
	built(id*2+2,dep-1),built(id*2+1,dep-1);
	if(typ[id]==2)num[id]=num[id*2+1]+num[id*2+2];
	if(typ[id]==1)num[id]=num[id*2+1];
	if(typ[id]==0)num[id]=num[id*2+2];
}
void upd(int id,int dep){
	if(dep==0){
		num[id]=(typ[id]==2)+1;
		if(id!=0)upd((id-1)/2,dep+1);
		return;
	}
	if(typ[id]==2)num[id]=num[id*2+1]+num[id*2+2];
	if(typ[id]==1)num[id]=num[id*2+1];
	if(typ[id]==0)num[id]=num[id*2+2];
	if(id!=0)upd((id-1)/2,dep+1);
}
int main(){
	cin>>K>>s;
	reverse(s.begin(),s.end());
	built(0,K-1);
	cin>>q;
	while(q--){
		int p;char c;
		cin>>p>>c;
		typ[(1<<K)-1-p]=t(c);
		upd((1<<K)-1-p,d[(1<<K)-1-p]);
		cout<<num[0]<<"\n";
	}
}