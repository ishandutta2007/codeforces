#include<stdio.h>
#include<stack>
using namespace std;
#define R register int
#define L long long
#define I inline
int m[500001],ans[500001];
L tot1[500001],tot2[500001];
bool v1[500001],v2[500001];
struct Building{
	int id,hei;
};
stack<Building>Q,P;
int main(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",m+i);
	}
	Building Tem;
	Tem.hei=0;
	Tem.id=0;
	Q.push(Tem);
	for(R i=1;i<=n;i++){
		Tem=Q.top();
		if(Tem.hei<m[i]){
			tot1[i]=tot1[i-1]+m[i];
		}else{
			while(Tem.hei>=m[i]){
				Q.pop();
				Tem=Q.top();
			}
			tot1[i]=tot1[Tem.id]+(L)m[i]*(i-Tem.id); 
		}
		Tem.hei=m[i];
		Tem.id=i;
		Q.push(Tem);
	}
	Tem.hei=0;
	Tem.id=n+1;
	P.push(Tem);
	for(R i=n;i!=0;i--){
		Tem=P.top();
		if(Tem.hei<m[i]){
			tot2[i]=tot2[i+1]+m[i];
		}else{
			while(Tem.hei>=m[i]){
				P.pop();
				Tem=P.top();
			}
			tot2[i]=tot2[Tem.id]+(L)m[i]*(Tem.id-i); 
		}
		Tem.hei=m[i];
		Tem.id=i;
		P.push(Tem);
	}
	while(Q.empty()==false){
		Q.pop();
	}
	while(P.empty()==false){
		P.pop();
	}
	L mx=0,id;
	for(R i=1;i<=n;i++){
		if(tot1[i]+tot2[i]-m[i]>mx){
			id=i;
			mx=tot1[i]+tot2[i]-m[i];
		}
	}
	Tem.hei=0;
	Tem.id=0;
	Q.push(Tem);
	for(R i=1;i<=id;i++){
		Tem=Q.top();
		if(Tem.hei<m[i]){
			tot1[i]=tot1[i-1]+m[i];
		}else{
			while(Tem.hei>=m[i]){
				Q.pop();
				Tem=Q.top();
			}
			tot1[i]=tot1[Tem.id]+(L)m[i]*(i-Tem.id); 
		}
		Tem.hei=m[i];
		Tem.id=i;
		Q.push(Tem);
	}
	Tem.hei=0;
	Tem.id=n+1;
	P.push(Tem);
	for(R i=n;i>=id;i--){
		Tem=P.top();
		if(Tem.hei<m[i]){
			tot2[i]=tot2[i+1]+m[i];
		}else{
			while(Tem.hei>=m[i]){
				P.pop();
				Tem=P.top();
			}
			tot2[i]=tot2[Tem.id]+(L)m[i]*(Tem.id-i); 
		}
		Tem.hei=m[i];
		Tem.id=i;
		P.push(Tem);
	}
	while(Q.size()>1){
		v1[Q.top().id]=true;
		Q.pop();
	}
	while(P.size()>1){
		v2[P.top().id]=true;
		P.pop();
	}
	int lt;
	for(R i=id;i!=0;i--){
		if(v1[i]==true){
			lt=m[i];
		}
		ans[i]=lt;
	}
	for(R i=id;i<=n;i++){
		if(v2[i]==true){
			lt=m[i];
		}
		ans[i]=lt;
	}
	for(R i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}