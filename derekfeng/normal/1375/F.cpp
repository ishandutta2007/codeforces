#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[3];
int a=0,b=1,c=2;
bool cmp(int x,int y){
	return A[x]<A[y];
}
int main(){
	cin>>A[0]>>A[1]>>A[2];
	if(cmp(b,a))swap(a,b);
	if(cmp(c,a))swap(a,c); 
	if(cmp(c,b))swap(b,c);
	puts("First");
	fflush(stdout); 
	cout<<2*A[c]-A[b]-A[a]<<"\n";
	fflush(stdout);
	int x;cin>>x;x--;
	if(x==a){cout<<A[c]-A[b]<<"\n";}
	if(x==b){cout<<A[c]-A[a]<<"\n";}
	if(x==c){
		cout<<A[c]*6-(A[b]+A[a])*3<<"\n";
		fflush(stdout);
		cin>>x,x--;
		if(x==a){
			cout<<3*A[c]-A[a]-2*A[b]<<"\n";
		}else{
			cout<<3*A[c]-A[b]-2*A[a]<<"\n";
		}
	}
	cin>>x;
}