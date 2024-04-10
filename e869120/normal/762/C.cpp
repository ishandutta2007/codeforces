#include<iostream>
#include<algorithm>
using namespace std;
int a[220000],b[220000];string S,T;
int J[220000],mi,mj,mn;
int main(){
	cin>>S>>T;
	int c=0;
	for(int i=0;i<(int)T.size();i++){
		while(c<(int)S.size() && S[c]!=T[i])c++;
		a[i]=c+1;c++;
	}
	int d=0;
	for(int i=(int)T.size()-1;i>=0;i--){
		while(d<(int)S.size() && S[(int)S.size()-1-d]!=T[i])d++;
		b[i]=d+1;d++;
	}
	for(int i=(int)T.size()-1;i>=0;i--){J[b[i]]=T.size()-i;}
	for(int i=1;i<=(int)S.size();i++){J[i]=max(J[i],J[i-1]);}
	
	/*for(int i=0;i<T.size();i++)cout<<a[i]<<' ';cout<<endl;
	for(int i=0;i<T.size();i++)cout<<b[i]<<' ';cout<<endl;*/
	
	for(int i=-1;i<(int)T.size();i++){
		if(i==-1){
			int pos1=J[S.size()];
			if(pos1+i+1>=(int)T.size()){cout<<T<<endl;return 0;}
			else if(i+1+pos1>mn){mi=i+1;mj=pos1;mn=i+1+pos1;}
		}
		else{
			if(a[i]>(int)S.size())continue;
			int pos1=J[(int)S.size()-a[i]];
			if(pos1+i+1>=(int)T.size()){cout<<T<<endl;return 0;}
			else if(i+1+pos1>mn){mi=i+1;mj=pos1;mn=i+1+pos1;}
		}
	}
	if(mn==0)cout<<"-"<<endl;
	else cout<<T.substr(0,mi)+T.substr(T.size()-mj,mj)<<endl;
	return 0;
}