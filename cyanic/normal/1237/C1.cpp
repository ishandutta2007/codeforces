#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
struct node{
	int x,y,z,mark;
	friend bool operator < (node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		if(a.y!=b.y)return a.y<b.y;
		return a.z<b.z;
	}
}p[N];
int n;

int main(){
	read(n);
	rep(i,1,n)
		read(p[i].x),read(p[i].y),read(p[i].z);
	rep(i,1,n)
		if(!p[i].mark){
			int d=1e9,k=0;
			rep(j,i+1,n)
				if(!p[j].mark){
					int t=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)
							+abs(p[i].z-p[j].z);
					if(t<d)d=t,k=j;
				}
			printf("%d %d\n",i,k);
			p[k].mark=1;
		}

	return 0;
}