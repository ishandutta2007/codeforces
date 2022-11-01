#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
int p[4][150000],ord[4][150000],D;
struct Dinner{
	int c[4],cost;
	I void Calc(){
		cost=p[0][ord[0][c[0]]]+p[1][ord[1][c[1]]]+p[2][ord[2][c[2]]]+p[3][ord[3][c[3]]];
	}
	I void Init(int A,int B,int C,int D){
		c[0]=A;
		c[1]=B;
		c[2]=C;
		c[3]=D;
		Calc();
	}
	I friend bool operator<(Dinner A,Dinner B){
		return A.cost>B.cost;
	}
};
I bool Compare(int x,int y){
	return p[D][x]<p[D][y];
}
int main(){
	int n[4],m[3],a,b;
	cin>>n[0]>>n[1]>>n[2]>>n[3];
	set<pair<int,int> >S[3];
	for(R i=0;i!=4;i++){
		for(R j=0;j!=n[i];j++){
			cin>>p[i][j];
			ord[i][j]=j;
		}
		D=i;
		sort(ord[i],ord[i]+n[i],Compare);
	}
	for(R i=0;i!=3;i++){
		cin>>m[i];
		for(R j=0;j!=m[i];j++){
			cin>>a>>b;
			S[i].insert(make_pair(a-1,b-1));
		}
	}
	Dinner Tem;
	Tem.Init(0,0,0,0);
	priority_queue<Dinner>Q;
	Q.push(Tem);
	while(Q.empty()==false){
		Tem=Q.top();
		Q.pop();
		int d=-1,f[4];
		for(R i=0;i!=4;i++){
			f[i]=ord[i][Tem.c[i]];
		}
		for(R i=0;i!=3;i++){
			if(S[i].count(make_pair(f[i],f[i+1]))!=0){
				d=i;
				break;
			}
		}
		if(d==-1){
			printf("%d",Tem.cost);
			return 0;
		}
		Dinner Tem2;
		if(Tem.c[d]+1!=n[d]){
			Tem2=Tem;
			Tem2.c[d]++;
			Tem2.Calc();
			Q.push(Tem2);
		}
		d++;
		if(Tem.c[d]+1!=n[d]){
			Tem2=Tem;
			Tem2.c[d]++;
			Tem2.Calc();
			Q.push(Tem2);
		}
	}
	printf("-1");
	return 0;
}