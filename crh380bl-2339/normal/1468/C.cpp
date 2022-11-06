#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
struct node{
	int m,id;
	bool operator <(const node &z)const{
		return m==z.m?id>z.id:m<z.m;
	}
}tmp;
queue<node>Q1;
priority_queue<node>Q2;
bool bo[500005];
int main(){
	int T,o,p,n=0;
			int tp;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&o);
		if(o==1){
			scanf("%d",&p);
			tmp.m=p;
			tmp.id=++n;
			Q1.push(tmp);
			Q2.push(tmp);
		}
		else if(o==2){
			while(bo[Q1.front().id])Q1.pop();
			bo[tp=Q1.front().id]=1;
			printf("%d ",tp);
			Q1.pop();
		}
		else{
			while(bo[Q2.top().id])Q2.pop();
			bo[tp=Q2.top().id]=1;
			printf("%d ",tp);
			Q2.pop();
		}
	}
	return 0;
}