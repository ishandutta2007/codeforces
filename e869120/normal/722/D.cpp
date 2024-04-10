#include<bits/stdc++.h>
using namespace std;
int L=1,R=(1<<30),P,a[70000],b[70000],n;
map<int,int>M;
bool search(int p){
	if(p==0)return false;
	M.clear();
	for(int i=0;i<n;i++){
		int Y=a[i];
		while(true){
			if(Y==0)return false;
			if(Y<=p && M[Y]==0){M[Y]=1;b[i]=Y;break;}
			Y/=2;
		}
	}
	return true;
}
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	while(true){
		P=(L+R)/2;
		bool H1=search(P-1),H2=search(P);
		if(H1==false && H2==true){
			for(int i=0;i<n;i++){if(i)cout<<' ';cout<<b[i];}cout<<endl;
			break;
		}
		if(H1==true)R=P;
		if(H2==false)L=P;
	}
	return 0;
}