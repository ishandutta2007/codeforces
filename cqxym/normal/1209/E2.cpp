#include<cstdio>
#include<algorithm>
using namespace std;
#define R register int
const int MAXN = 12;
const int MAXM = 2000;
int a[13][2001],n,m,f[10000],g[10000],h[10000],L[10000];
int LowB(int x){
	return x&-x;
}
struct node{
    int key,id;
    friend bool operator<(node a,node b){
        return a.key > b.key;
    }
}A[2001];
bool T[2001];
void Solve(){
    scanf("%d%d",&n,&m);
    for(R j=1;j<=m;j++){
    	T[j]=false;
		A[j].key=0;
		A[j].id=j;
	}
    for(R i=0;i<n;i++){
        for(int j=1;j<=m;j++){
        	scanf("%d",&a[i][j]);
			A[j].key=max(A[j].key,a[i][j]);
		}
	}
    sort(A+1,A+m+1);
    for(R i=1;i<=m&&i<=n;i++){
    	T[A[i].id]=true;
	}
    int Q=1<<n;
    for(R j=0;j<Q;j++){
    	f[j]=0;
	}
    for(R j=0;j<n;j++){
    	L[1<<j]=j;
	}
    for(R i=1;i<=m;i++){
        if(T[i]==false){
        	continue;
		}
        for(R j=0;j<Q;j++){
        	h[j]=0;
		}
        for(R j=1;j<=n;j++){
            for(R k=0;k<Q;k++){
            	g[k]=f[k];
			}
            for(R k=0;k<Q;k++){
                int p=(Q-1)^k;
                while(p>0){
                    int x=LowB(p),y=L[x];
                    g[k|x]=max(g[k|x],g[k]+a[y][i]);
                    p-=x;
                }
            }
            int Tp=a[0][i];
            for(R k=0;k<n-1;k++){
            	a[k][i]=a[k+1][i];
			}
            a[n-1][i]=Tp;
            for(R j=0;j<Q;j++){
            	h[j]=max(h[j],g[j]);
				g[j]=0;
			} 
        }
        for(R j=0;j<Q;j++){
        	f[j]=h[j];
		}
    }
    printf("%d\n",f[Q-1]);
}
int main() {
    int t;
	scanf("%d", &t);
    for(R i=0;i<t;i++){
    	Solve();
	}
	return 0;
}