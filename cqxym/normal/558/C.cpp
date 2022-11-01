#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define R register int
#define I inline
int ct[100001],n,step;
struct Num{
	int odd,power,org,id;
	I friend bool operator<(Num x,Num y){
		return x.odd<y.odd;
	}
}a[100001];
I bool Com(Num &x,Num &y){
	return x.power<y.power;
}
I Num Dev(int x,int ID){
	Num ans;
	ans.id=ID;
	ans.org=x;
	ans.power=0;
	while((x&1)==0){
		x>>=1;
		ans.power++;
	}
	ans.odd=x;
	return ans;
}
I void Total(){
	sort(a,a+n,Com);
	int mid=n>>1;
	/*for(R i=0;i!=n;i++){
		printf("%d ",a[i].power);
	}*/
	for(R i=0;i!=mid;i++){
		step+=a[mid].power-a[i].power;
	}
	for(R i=mid+1;i!=n;i++){
		step+=a[i].power-a[mid].power;
	}
	printf("%d",step);
}
int main(){
	int x;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		a[i]=Dev(x,i);
		//printf("Q%d %d %d\n",a[i].odd,a[i].power,a[i].org);
		ct[a[i].odd]++;
		if(ct[a[i].odd]==n){
			Total();
			return 0;
		}
	}
	priority_queue<Num>Q;
	for(R i=0;i!=n;i++){
		Q.push(a[i]);
	}
	do{
		Num tem=Q.top();
		//printf("A%d\n",tem.org);
		Q.pop();
		step++;
		if(tem.power!=0){
			tem.power--;
			tem.org>>=1;
			a[tem.id]=tem;
			Q.push(tem);
		}else{
			ct[tem.odd]--;
			tem=Dev(tem.org>>1,tem.id);
			a[tem.id]=tem;
			//printf("Y%d %d %d %d\n",tem.odd,tem.org,tem.power,tem.id);
			ct[tem.odd]++;
			if(ct[tem.odd]==n){
				Total();
				return 0;
			}
			Q.push(tem);
		}
	}while(true);
}