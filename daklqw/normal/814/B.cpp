#include <iostream>
using namespace std;
int n,a[1010],b[1010],at[10],co=0,no,ttt,t;
char v[1010];
bool pd(){
	int count=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])++count;
	if(count==1)return true;
	else return false;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];++v[a[i]];}
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)if(!v[i])no=i;else if(v[i]==2)ttt=i;
	for(int i=1;i<=n;i++)if(a[i]==ttt)at[++co]=i;
	t=a[at[1]];
	a[at[1]]=no;
	if(!pd())a[at[1]]=t,a[at[2]]=no;
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}