/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n;
int a[N+1];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int las;
	for(int i=n;i;i--){// 
		if(i<n&&a[i]<a[i+1])break;
		las=i;
	}
	int las0;
	for(int i=las;i;i--){// 
		if(i<las&&a[i]>a[i+1])break;
		las0=i;
	}
	cout<<las0-1<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}