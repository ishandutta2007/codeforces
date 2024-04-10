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

int main(){
  //  judge();
	int n,m;read(n);read(m);bool flag=0;
	for(;;){
		bool succ=0;
		if(flag==0){
			if(n>=2&&m>=2){
				n-=2;m-=2;succ=1;
			}
			else{
				if(n>=1&&m>=12){
					n-=1;m-=12;succ=1;
				}
				else {
					if(m>=22){
						m-=22;succ=1;
					}
				}
			}
			if(!succ){
				puts("Hanako");return 0;
			}
		}
		else{
			if(m>=22){
				m-=22;succ=1;
			}			
			else if(n>=1&&m>=12){
				n-=1;m-=12;succ=1;
			} 
			else if(n>=2&&m>=2){
				n-=2;m-=2;succ=1;
			}
			if(!succ){puts("Ciel");return 0;}
		}
		flag^=1;
	}
    return 0;
}