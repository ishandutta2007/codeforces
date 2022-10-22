/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int N=100000;
int n;
int a[N+1];
pair<bool,vector<int> > sol(int x){
	bool flg=true;
	flg&=a[n]>a[x];
	for(int i=1;i<=x;i++)flg&=a[n-i]>a[x-i+1];
	if(!flg)return mp(false,vector<int>());
	vector<int> res(n);
	for(int i=1;i<=x;i++)res[2*(x-i+1)-1]=a[x-i+1],res[2*(x-i+1)-2]=a[n-i];
	res[2*x]=a[n];
	for(int i=2*x+1;i<n;i++)res[i]=a[x+i-2*x];
	return mp(true,res);
}
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	pair<int,vector<int> > ans;
	ans.X=0;
	for(int i=1;i<=n;i++)ans.Y.push_back(a[i]);
	for(int i=25;~i;i--)if(ans.X+(1<<i)<=n-1>>1){
		pair<bool,vector<int> > p=sol(ans.X+(1<<i));
		if(p.X)ans=mp(ans.X+(1<<i),p.Y);
	}
	cout<<ans.X<<"\n";
	for(int i=1;i<=n;i++)printf("%d ",ans.Y[i-1]);puts("");
}
int main(){
	int testnum=1;
//	cin>>testnum;
	while(testnum--)mian();
	return 0;
}