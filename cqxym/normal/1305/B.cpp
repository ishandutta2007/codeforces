#include<iostream>
#include<vector>
using namespace std;
#define R register int
int a[1000],b[1000];
int main(){
	string s;
	cin>>s;
	int l=s.length();
	if(s[0]=='('){
		a[0]=1;
	}
	for(R i=1;i!=l;i++){
		a[i]=a[i-1];
		if(s[i]=='('){
			a[i]++;
		}
	}
	if(s[l-1]==')'){
		b[l-1]=1;
	}
	for(R i=l-2;i!=-1;i--){
		b[i]=b[i+1];
		if(s[i]==')'){
			b[i]++;
		}
	}
	int mx=0,id=-1;
	for(R i=0;i!=l;i++){
		int tem=min(a[i],b[i]);
		if(tem>mx){
			id=i;
			mx=tem;
		}
	}
	if(id==-1){
		printf("0");
	}else{
		printf("1\n%d\n",mx<<1);
		for(R i=0;i<=id;i++){
			if(s[i]=='('){
				printf("%d ",i+1);
			}
		}
		vector<int>A;
		for(R i=l-1;mx!=0;i--){
			if(s[i]==')'){
				A.push_back(i+1);
				mx--;
			}
		}
		for(R i=A.size()-1;i!=-1;i--){
			printf("%d ",A[i]);
		}
	}
	return 0;
}