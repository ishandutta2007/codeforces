#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a1,b1,a2,b2;
int n;
bool get(int a,int b,int c,int d){
	cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	fflush(stdout);
	int ans;
	cin>>ans;
	return ans&1;
}
int main(){
	srand((unsigned)time(0));
	cin>>n;
	int np=0;
	if(n==1000){
		while(!np) np=rand()%1001;
	}
	int i,j;
	for(i=1;i<=n;i++){
		if(i==np) continue;
		if(get(1,i,n,i)){
			if(!b1) b1=i;
			else b2=i;
		}
	}
	for(i=1;i<=n;i++){
		if(get(i,1,i,n)){
			if(!a1) a1=i;
			else a2=i;
		}
	}
	if(!b1){
		int l=1,r=n;
		while(r>l){
			int mid=(l+r)/2;
			if(get(a1,1,a1,mid)) r=mid;
			else l=mid+1;
		}
		b1=l;
		l=1;r=n;
		while(r>l){
			int mid=(l+r)/2;
			if(get(a2,1,a2,mid)) r=mid;
			else l=mid+1;
		}
		b2=l;
		cout<<"! "<<a1<<" "<<b1<<" "<<a2<<" "<<b2;
		return 0;
	}
	else {
		int l=1,r=n;
		while(r>l){
			int mid=(l+r)/2;
			if(get(1,b1,mid,b1)) r=mid;
			else l=mid+1;
		}
		a1=l;
		l=1;r=n;
		while(r>l){
			int mid=(l+r)/2;
			if(get(1,b2,mid,b2)) r=mid;
			else l=mid+1;
		}
		a2=l;
		cout<<"! "<<a1<<" "<<b1<<" "<<a2<<" "<<b2;
		return 0;
	}
}