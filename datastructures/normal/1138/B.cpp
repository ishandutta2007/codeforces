#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5005][2],cnt[3],s; 
char x;
void out(int a0,int a1,int a2){
	int tot0=0,tot1=0,tot2=0;
	for (int i=1;i<=n;i++){
		if (a[i][0]+a[i][1]==0&&tot0<a0)tot0++,cout<<i<<' ';
		if (a[i][0]+a[i][1]==1&&tot1<a1)tot1++,cout<<i<<' ';
		if (a[i][0]+a[i][1]==2&&tot2<a2)tot2++,cout<<i<<' ';
	}
	cout<<endl;
	return;
}
int main(){
//	freopen("1138B.in","r",stdin); 
//	freopen("1138B.out","w",stdout);
	cin>>n;
	for (int j=0;j<=1;j++)
		for (int i=1;i<=n;i++)
			cin>>x,a[i][j]=x-'0';
	for (int i=1;i<=n;i++)cnt[a[i][0]+a[i][1]]++,s+=a[i][1];
	for (int a0=0;a0<=cnt[0];a0++){
		int a1,a2;
		a2=s-(n/2-a0);
		a1=s-a2*2;
		if (a1>=0&&a1<=cnt[1]&&a2>=0&&a2<=cnt[2]){
			out(a0,a1,a2);
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}