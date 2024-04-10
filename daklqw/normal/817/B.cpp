#include <iostream>
#include <algorithm>
using namespace std;
int list[110000],n,c[4],at=1,t;
unsigned long long ans=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>list[i];
	sort(list+1,list+1+n);++c[1];
	for(int i=2;i<=n;i++){
		if(list[i]>list[i-1]){if(at==3)break;c[++at]++;}
		else ++c[at];
	}
	if(c[1]>=3)ans=((unsigned long long)c[1])*(c[1]-1)*(c[1]-2)/6;
	else if(c[1]==2)ans=c[2];
	else{if(c[2]==1)ans=c[3];else ans=((unsigned long long)c[2])*(c[2]-1)/2;}
	cout<<ans<<endl;
	return 0;
}