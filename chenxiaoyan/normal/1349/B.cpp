/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n,m;
int a[N+1];
int Sum[N+1];
int Odd[N+1],Evn[N+1];
void mian(){
	cin>>n>>m;
	bool ok=false;
	for(int i=1;i<=n;i++)cin>>a[i],ok|=a[i]==m;
	if(!ok)return puts("no"),void();
	if(n==1)return puts("yes"),void();
	for(int i=1;i<=n;i++)Sum[i]=Sum[i-1]+(a[i]>=m);
	for(int i=1;i<=n;i++){
		Odd[i]=Odd[i-1];Evn[i]=Evn[i-1];
		if(i&1)Odd[i]=min(Odd[i],2*Sum[i-1]-i);
		else Evn[i]=min(Evn[i],2*Sum[i-1]-i);
	}
	for(int i=1;i<=n;i++){
		if(i&1){
			if(2*Sum[i]-i-Evn[i-1]>=3)return puts("yes"),void();
			if(2*Sum[i]-i-Odd[i-1]>=2)return puts("yes"),void();
		}
		else{
			if(2*Sum[i]-i-Odd[i-1]>=3)return puts("yes"),void();
			if(2*Sum[i]-i-Evn[i-1]>=2)return puts("yes"),void();
		}
	}
	puts("no");
}
int main(){
	int testnum;
	cin>>testnum;
	Odd[0]=Evn[0]=0x3f3f3f3f;
	while(testnum--)mian();
	return 0;
}