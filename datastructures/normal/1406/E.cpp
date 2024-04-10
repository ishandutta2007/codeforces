#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,p[100005],isd[100005],ans=1,tot,num,b=100;
inline bool isp(register int x){
	for (register int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}
inline int q_a(register int x){
	if (x>n)return 0;
	int num;
	cout<<'A'<<' '<<x<<endl;
	cin>>num;
	return num;
}
inline void q_b(register int x){
	if (x>n)return;
	int num;
	cout<<'B'<<' '<<x<<endl;
	cin>>num;
	return;
}
inline void del(register int x){
	for (register int i=x;i<=n;i+=x)isd[i]=1;
	return;
}
inline int ask(register int x){
	int num=0;
	for (register int i=x;i<=n;i+=x)num+=1-isd[i];
	return num;
}
signed main(){
	cin>>n;
	for (register int i=2;i<=n;i++)
		if (isp(i))p[++tot]=i;
	for (register int i=tot;p[i]*p[i]>n;i--){
		++num;
		q_b(p[i]);
		del(p[i]);
		if (num%b==0||p[i-1]*p[i-1]<=n){
			if (ask(1)==q_a(1))continue;
			register int now=i;
			while(ask(p[now])==q_a(p[now]))now++;
			ans*=p[now];
			break;
		}
	}
	for (register int i=1;i<=tot&&p[i]*p[i]<=n;i++){
		q_b(p[i]); 
		del(p[i]);
		int now=p[i];
		while(now<=n&&q_a(now)>0)ans*=p[i],now*=p[i];
	}
	cout<<'C'<<' '<<ans<<endl;
	return 0;
}