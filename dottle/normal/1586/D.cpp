#include<bits/stdc++.h>
//#define int long long
const int N=100050;
using namespace std;

int n,a[N];

void ask(int k){
	if(k>0){
		cout<<"?";
		for(int i=1;i<n;i++)cout<<' '<<k+1;
		cout<<' '<<1;
		cout<<endl;
		return ;
	}else{
		cout<<"?";
		for(int i=1;i<n;i++)cout<<' '<<1;
		cout<<' '<<-k+1;
		cout<<endl;
		return ;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	int nw=n+1,fl=0,x;
	do{
		nw--;
		if(nw==1)break;
		ask(nw-1);
		cin>>x;
		if(x)fl=1;	
	}while(!fl);
	a[n]=nw;
	for(int i=1;i<=n;i++)
		if(i!=nw)
			ask(nw-i),cin>>x,a[x]=i;
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<' '<<a[i];
}