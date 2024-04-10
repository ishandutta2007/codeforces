#include<stdio.h>
#include<algorithm>
#define R register int
#define I inline
I int Max(const int x,const int y){
	return x>y?x:y;
}
struct Hiker{
	int Skill,Val;
	I void Read(){
		scanf("%d%d",&Skill,&Val);
	}
	I friend bool operator<(Hiker A,Hiker B){
		int a=Max(A.Skill,A.Val),b=Max(B.Skill,B.Val);
		if(a!=b){
			return a<b;
		}
		return A.Skill<B.Skill;
	}
}p[500000];
int main(){
	int n,d,ans=0;
	scanf("%d%d",&n,&d);
	for(R i=0;i!=n;i++){
		p[i].Read();
	}
	std::sort(p,p+n);
	for(R i=0;i!=n;i++){
		if(p[i].Skill>=d){
			ans++;
			d=Max(d,p[i].Val);
		}
	}
	printf("%d",ans);
	return 0;
}