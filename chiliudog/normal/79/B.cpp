#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
set<pin> zball;
typedef set<pin>::iterator It;
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
int n,m,k,t;
string ans[3];
int main(){
 //   judge();
	read(n);read(m);read(k);read(t);
	ans[0]="Grapes";ans[1]="Carrots";ans[2]="Kiwis";
	rep(i,1,k){
		int a,b;read(a);read(b);zball.insert(mk(a,b));
	}
	rep(i,1,t){
		int x,y;read(x);read(y);
		if(zball.count(mk(x,y))){
			puts("Waste");continue;
		}
		int rk=(x-1)*m+y;
		zball.insert(mk(x,y));It it=zball.find(mk(x,y));
		while(it!=zball.begin()){
			rk--;it--;
		}zball.erase(mk(x,y));
		cout<<ans[rk%3]<<endl;
	}
    return 0;
}