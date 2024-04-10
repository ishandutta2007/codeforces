/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int H=20;
int h,g;
int a[(1<<H+2)];
int f0(int i,int now){
	int l=2*i,r=2*i+1;
	if(a[l]==0&&a[r]==0)return now;
	else
		if(a[l]>a[r])return f0(l,now+1);
		else return f0(r,now+1);
}
void f(int i){
	int l=2*i,r=2*i+1;
	if(a[l]==0&&a[r]==0)a[i]=0;
	else
		if(a[l]>a[r])a[i]=a[l],f(l);
		else a[i]=a[r],f(r);
}
vector<int> ans;
void deal(int x=1,int now=1){
//	cout<<x<<"!\n";
	if(a[x]==0)return;
//	cout<<f0(x,now)<<"=f0(x)\n";
	while(f0(x,now)>g){
		ans.push_back(x),f(x);
//		for(int i=1;i<1<<h;i++)cout<<a[i]<<" ";puts("!");
	}
	deal(x<<1,now+1);deal(x<<1|1,now+1);
}
void mian(){
	cin>>h>>g;
	for(int i=1;i<1<<h+2;i++)a[i]=0;
	for(int i=1;i<1<<h;i++)scanf("%lld",a+i);
	ans.clear();
	deal();
	int sum=0;
	for(int i=1;i<1<<g;i++)sum+=a[i];
	printf("%lld\n",sum);
	for(int i=0;i<ans.size();i++)printf("%lld ",ans[i]);
	puts("");
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}