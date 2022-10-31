#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k;
int findDish(int u,int v,int key)
{
	string s;
	int t;
	if(u==v){
		return u;
	}
	if(u==v-1){
		cout<<1<<" "<<u<<" "<<v<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='T'){
			return u;
		}
		else return v;
	}
	t=(u+v+key)/2;
	cout<<1<<" "<<t<<" "<<t+1<<endl;
	fflush(stdout);
	cin>>s;
	if(s[0]=='T') return findDish(u,t,key);
	return findDish(t+1,v,key);
}
int main()
{
	cin>>n>>k;
	int ansA=findDish(1,n,0);
	int ansB=findDish(1,ansA,-1);
	if(ansB==-1||ansB==ansA) ansB=findDish(ansA+1,n,1);
	cout<<2<<" "<<ansA<<" "<<ansB<<endl;
	return 0;
}