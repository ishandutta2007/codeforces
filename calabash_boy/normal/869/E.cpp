#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2550;
const int BAS = 146527;
int m,n,q;
LL bit[maxn][maxn];
inline LL lowbit(LL x){
	return x&(-x);
}
inline LL has(int x1,int y1,int x2,int y2){
	LL res =1LL*x1*BAS;
	res +=y1;
	res*=BAS;
	res+=x2;
	res*=BAS;
	res+=y2;
	return res;
}
void add(int x,int y,int val){
	for (int i =x;i<=n;i+=lowbit(i)){
		for (int j=y;j<=m;j+=lowbit(j)){
			bit[i][j]+=val;
		}
	}
}
void update(int x1,int y1,int x2,int y2,int flag){
	LL val = flag*has(x1,y1,x2,y2);
//	cout<<val<<endl;
	add(x2+1,y2+1,-val);
	add(x1,y2+1,val);
	add(x2+1,y1,val);
	add(x1,y1,-val);
}
LL sum(int x,int y){
	LL res =0;
	for (int i=x;i;i-=lowbit(i)){
		for (int j=y;j;j-=lowbit(j)){
			res+=bit[i][j];
		}
	}
	return res;
}
void solve(int x1,int y1,int x2,int y2){
//	cout<<sum(x1,y1)<<endl;
//	cout<<sum(x2,y2)<<endl;
	if (sum(x1,y1)==sum(x2,y2)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	while (q--){
		int op,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&op,&x1,&y1,&x2,&y2);
		if (op==1){
			update(x1,y1,x2,y2,1);
		}else if (op==2){
			update(x1,y1,x2,y2,-1);
		}else{
			solve(x1,y1,x2,y2);
		} 
	}
	return 0;
}