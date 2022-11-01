#include<stdio.h>
#include<map>
#include<set>
using namespace std;
#define R register int
char BF[1<<20],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=BF)+fread(BF,1,1<<20,stdin),p1==p2)?0:*p1++)
inline void Read(int &x){
    char t=GC;
    x=0;
    while(t<48||t>57){
        t=GC;
    }
    while(t>47&&t<58){
        x=(x<<3)+(x<<1)+t-48;
        t=GC;
    }
}
map<int,int>P;
set<int>Q;
int ans[1001];
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
inline void Delete(int x){
	if(P[x]==1){
		Q.erase(x);
	}
	P[x]--;
}
int main(){
	int n,x;
	Read(n);
	for(R i=0;i!=n*n;i++){
		Read(x);
		Q.insert(x);
		P[x]++;
	}
	if(n==1){
		printf("%d",x);
		return 0;
	}
	set<int>::iterator T=Q.end();
	T--;
	ans[n-1]=*T;
	Delete(ans[n-1]);
	for(R i=n-2;i!=-1;i--){
		T=Q.end();
		T--;
		ans[i]=*T;
		Delete(ans[i]);
		for(R j=i+1;j!=n;j++){
			x=Gcd(ans[i],ans[j]);
			P[x]--;
			Delete(x);
		}
	}
	for(R i=0;i!=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}