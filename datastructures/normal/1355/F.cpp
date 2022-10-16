#include <iostream>
#include <cstdio>
#define ll long long
#define inf 1000000000000000000
using namespace std;
bool isp(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}
int t;
int p[1005],tot;
int cnt;
int getcnt(int x){
	ll qwq=x;
	while(qwq<=inf/x)qwq*=x;
	cout<<"? "<<qwq<<endl;
	cnt++;
	fflush(stdout);
	int awa;
	cin>>awa;
	int ans=0;
	while(awa%x==0)ans++,awa/=x;
	return ans; 
}
int main(){
	for (int i=2;i<=1000;i++)
		if (isp(i))p[++tot]=i;
	cin>>t;
	while(t--){
		cnt=0;
		int d=1;
		for (int i=1;i<=tot&&cnt<22;i++){
			int j=i;
			ll now=p[i];
			while(now<=inf/p[j+1])now*=p[j],j++;
			cout<<"? "<<now<<endl;
			cnt++;
			fflush(stdout);
			int x;
			cin>>x;
			for (int k=i;k<=j&&cnt<22;k++)
				if (x%p[k]==0)d*=getcnt(p[k])+1;
			i=j;
		}
		if (d<=2){
			cout<<"! "<<d+7<<endl;
			fflush(stdout);
		} 
		else{
			cout<<"! "<<d*2<<endl;
			fflush(stdout); 
		} 
	}
	return 0;
}