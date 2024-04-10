#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=505*505;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[maxn],ans[maxn];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
priority_queue<int> heap;
map<int,int> zball;
inline int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
inline void forever(int x){
	if (zball.count(x))zball[x]+=2;
	else zball[x]=2;
}
int main(){
 //   judge();
	int n;read(n);
	fortodo(i,1,n*n)read(a[i]);
	if (n==1){
		printf("%d",a[1]);return 0;
	}
	fortodo(i,1,n*n)heap.push(a[i]);
	ans[1]=heap.top();heap.pop();
	ans[2]=heap.top();heap.pop();
	zball[gcd(ans[1],ans[2])]=2;
	fortodo(i,3,n){
		int tmp=heap.top();heap.pop();
		while(zball.count(tmp)!=0){
			zball[tmp]--;
			if (zball[tmp]==0)zball.erase(tmp);
			tmp=heap.top();heap.pop();
		}
		ans[i]=tmp;
		fortodo(j,1,i-1)forever(gcd(ans[i],ans[j]));
	}
	fortodo(i,1,n)printf("%d ",ans[i]);
    return 0;
}