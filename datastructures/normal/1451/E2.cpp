#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100005],book[100005],id1,id2;
int ans[100005];
inline int ask(int a,int b,int opt){
	if (opt==1)cout<<"AND"<<' '<<a<<' '<<b<<endl;
	if (opt==2)cout<<"OR"<<' '<<a<<' '<<b<<endl;
	if (opt==3)cout<<"XOR"<<' '<<a<<' '<<b<<endl;
	int x;
	cin>>x;
	return x; 
}
inline void upd(){
	for (register int i=2;i<=n;i++)ans[i]=ans[1]^a[i];
	return;
}
inline void out(){
	cout<<"! ";
	for (register int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return;
} 
int main(){
	cin>>n;
	for (int i=2;i<=n;i++)a[i]=ask(1,i,3);
	for (int i=1;i<=n;i++){
		if (book[a[i]]==0)book[a[i]]=i;
		else id1=book[a[i]],id2=i;
	}
	if (id1==0&&id2==0){
		for (int i=2;i<=n;i++)
			if (a[i]==1){
				ans[1]=ask(1,i,1);
				break;
			}
		for (int i=2;i<=n;i++)
			if (a[i]%2==0){
				ans[1]+=(ask(1,i,1)&1);
				break;
			}
		upd();
	}
	else{
		ans[id1]=ans[id2]=ask(id1,id2,1);
		ans[1]=a[id1]^ans[id1];
		upd();
	}
	out();
	return 0;
}