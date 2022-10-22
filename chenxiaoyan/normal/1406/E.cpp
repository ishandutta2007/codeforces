/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
bool ispr(int x){
	if(x<2)return false;
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
int A(int x){
	printf("A %d\n",x),fflush(stdout);
	cin>>x;return x;
}
int B(int x){
	printf("B %d\n",x);fflush(stdout);
	cin>>x;return x;
}
void C(int x){printf("C %d\n",x);fflush(stdout);exit(0);}
void mian(){
	int n;
	cin>>n;
	if(n==1)C(1);
	vector<int> pr;
	for(int i=2;i<=n;i++)if(ispr(i))pr.pb(i);
	int x=1,lim=sqrt(n);
	for(int i=0;pr[i]<=lim;i++){
		B(pr[i]);
		int now=1;
		while(now*pr[i]<=n)now*=pr[i];
		while(now>1){
			if(A(now)==1){x*=now;break;}
			now/=pr[i];
		}
	}
	vector<int> v;
	for(int i=0;i<pr.size();i++)if(pr[i]>lim)v.pb(pr[i]);
	if(x==1){
		int now=A(1);
		for(int i=0;i<v.size();i+=100){
			for(int j=i;j<i+100&&j<v.size();j++)B(v[j]);
			int res=A(1);
			if(now-res==min(i+100,int(v.size()))-i)now=res;
			else{
				for(int j=i;j<i+100&&j<v.size();j++)if(A(v[j])==1){x=v[j];break;}
				break;
			}
		}
	}
	else{
		for(int i=0;i<v.size();i++)if(1ll*x*v[i]<=n&&A(x*v[i])==1){x*=v[i];break;}
	}
	C(x);
}
int main(){
	int testnum=1;
//	cin>>testnum;
	while(testnum--)mian();
	return 0;
}