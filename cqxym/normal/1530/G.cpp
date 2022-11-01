#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
char a[2002],b[2002];
I int Find(char*S,const int n){
	int pos=n;
	while(S[pos]=='0'){
		pos--;
	}
	return pos;
}
I void GetZip(char*S,const int n,vector<int>&A){
	int cur=0;
	for(R i=1;i<=n;i++){
		if(S[i]=='1'){
			A.push_back(i-cur-1);
			cur=i;
		}
	}
	A.push_back(n-cur);
}
I auto Reverse(vector<int>&P,int l,int r,const bool type){
	int idL=1,idR=0;
	for(R i=0;i!=l;i++){
		idL+=P[i]+1;
	}
	for(R i=0;i!=r;i++){
		idR+=P[i]+1;
	}
	if(type==true){
		P[r]+=P[l];
		P[l]=0;
	}else{
		idL+=P[l];
		idR+=P[r];
		P[l]+=P[r];
		P[r]=0;
	}
	reverse(P.begin()+l+1,P.begin()+r);
	auto res=make_pair(idL,idR);
	return res;
}
I void MakeToSTD(const int k,vector<int>&P,vector<pair<int,int>>&A){
	int n=P.size();
	for(R i=n-1;i!=k+1;i--){
		if(P[i]!=0){
			A.push_back(Reverse(P,i-k,i,false));
		}
	}
	for(R i=0;i<=k;i++){
		A.push_back(Reverse(P,0,k,false));
		A.push_back(Reverse(P,1,k+1,(k&1)==1?false:true));
	}
}
I void Solve(){
	int n,k,ct=0,ctb=0;
	scanf("%d%d",&n,&k);
	scanf("%s%s",a+1,b+1);
	bool tag=true;
	for(R i=1;i<=n;i++){
		if(a[i]=='1'){
			ct++;
		}
		if(b[i]=='1'){
			ctb++;
		}
		if(a[i]!=b[i]){
			tag=false;
		}
	}
	if(tag==true){
		puts("0");
		return;
	}
	if(k==0||ct!=ctb||k>ct){
		puts("-1");
		return;
	}
	vector<pair<int,int>>A,B;
	if(k==ct){
		int pos;
		if(a[1]=='0'){
			pos=Find(a,n);
			reverse(a+1,a+pos+1);
			A.push_back(make_pair(1,pos));
		}
		if(b[1]=='0'){
			pos=Find(b,n);
			reverse(b+1,b+pos+1);
			B.push_back(make_pair(1,pos));
		}
		tag=true;
		for(R i=1;i<=n;i++){
			if(a[i]!=b[i]){
				tag=false;
				break;
			}
		}
		if(tag==false){
			pos=Find(b,n);
			B.push_back(make_pair(1,pos));
			reverse(b+1,b+pos+1);
			tag=true;
			for(R i=1;i<=n;i++){
				if(a[i]!=b[i]){
					tag=false;
					break;
				}
			}
		}
		if(tag==false){
			puts("-1");
			return;
		}
	}else{
		vector<int>PA,PB;
		GetZip(a,n,PA);
		GetZip(b,n,PB);
		MakeToSTD(k,PA,A);
		MakeToSTD(k,PB,B);
		if((k&1)==0){
			for(R i=0;i<=ct;i++){
				if(PA[i]!=PB[i]){
					puts("-1");
					return;
				}
			}
		}
	}
	printf("%d\n",A.size()+B.size());
	for(auto T:A){
		printf("%d %d\n",T.first,T.second);
	}
	for(auto T=B.rbegin();T!=B.rend();T++){
		printf("%d %d\n",T->first,T->second);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}