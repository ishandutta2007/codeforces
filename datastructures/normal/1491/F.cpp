#include <iostream>
using namespace std;
int t,n,x,i,p,l,r,m,s,L,w[2005];
bool a(int l,int r,int I){
	cout<<'?'<<' '<<1<<' '<<r-l+1<<endl;
	cout<<I<<endl;
	while(r>=l)cout<<(--r)+1<<' ';cout<<endl;
	cin>>x;
	return x!=0;
} 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		i=2;
		while(a(1,i-1,i)==0)i++;
		p=i;
		l=1,r=i-1,s=0;
		while(l<=r){
			m=(l+r)/2;
			if (a(m,i-1,i)==1)l=m+1,s=m;
			else r=m-1;
		}
		L=0;
		for (i=p+1;i<=n;i++)
			if (!a(i,i,p))w[++L]=i;
		for (i=1;i<p;i++)
			if (i!=s)w[++L]=i;
		cout<<"! "<<L<<' ';
		for (i=1;i<=L;i++)cout<<w[i]<<' ';
		cout<<endl;
	}
}