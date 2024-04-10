#include<bits/stdc++.h>
using namespace std;
int M=1e9;
int ask(int x,int y){
	cout<<"? "<<x<<' '<<y<<endl;
	cin>>x;
	return x;
}
int main(){
	int s=ask(1,1),k;
	int u,v,l=1,r=M,mid;
	while(r>l+1){
		mid=l+r>>1;
		k=ask(1,mid);
		if(k+mid-1!=s)r=mid;
		else l=mid;
	}
	u=ask(1,l)+1;
	v=l;
	printf("! %d %d %d %d",u,v,v-1+M-ask(M,1),u-1+M-ask(1,M));
	return 0;
}