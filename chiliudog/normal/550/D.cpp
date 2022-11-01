#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=1000000;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int n,cnt,head[maxn],t[maxn<<1],ne[maxn<<1],num;
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
int main(){
  //  judge();
	read(n);
	if (n%2==0){
		puts("NO");return 0;
	}
	fortodo(i,1,4*n-2) head[i]=-1;
	fortodo(i,2,n) addedge(1,i);
	fortodo(j,2,n) fortodo(i,n+1,n+n-1) addedge(i,j);
	fortodo(i,1,(n-1)/2) addedge(n+(2*i-1),n+(2*i));
	int step=2*n-1;
	addedge(1,step+1);
	fortodo(i,2,n) addedge(step+1,step+i);
	fortodo(j,2,n) fortodo(i,n+1,n+n-1) addedge(step+i,step+j);
	fortodo(i,1,(n-1)/2) addedge(step+n+(2*i-1),step+n+(2*i));
	printf("YES\n%d %d\n",4*n-2,(4*n-2)*n/2);
	fortodo(i,1,4*n-2){
		for(int j=head[i];j!=-1;j=ne[j]){
			if (t[j]>i)
				printf("%d %d\n",i,t[j]);
		}
	}
    return 0;
}