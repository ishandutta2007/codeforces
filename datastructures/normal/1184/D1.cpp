#include <iostream>
#include <cstdio>
using namespace std;
int len,k,m,t;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>len>>k>>m>>t;
	while(t--){
		int f,i;
		cin>>f>>i;
		if (f==0){
			if (i<k)k=k-i,len-=i;
			else len=i;
		}
		if (f==1){
			if (i<=k)k++,len++;
			else len++;
		}
		cout<<len<<' '<<k<<endl;
	}
}