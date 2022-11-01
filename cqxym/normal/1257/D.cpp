#include<stdio.h>
#include<algorithm>
#define R register int
const int N=200001;
int a[N];
struct Node{
    int p,s;
}b[N];
inline bool Com(Node x,Node y){
	return x.s>y.s;
}
int z[N];
inline int Max(int x,int y){
	return x>y?x:y;
}
inline void Solve(){
	int n,m;
	scanf("%d", &n);
    for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
    scanf("%d", &m);
    for(R i=0;i!=m;i++){
        int s,p;
        scanf("%d%d",&p,&s);
        b[i].p=p;
        b[i].s=s;
    }
    std::sort(b,b+m,Com);
    z[0] = 0;
    int M=0,S=0;
    for(R i=n+2;i!=0;i--){
        while(S<m&&b[S].s>=i){
            M=Max(b[S].p,M);
            S++;
        }
        z[i]=M;
    }
    int ans=0;
    S=0;
    R E=0;
    while(S<n){
        M=a[E+1];
        while(E<n&&z[E+1-S]>=M){
			++E;
			M=Max(M,a[E+1]);
		}
        ans++;
        if(E==S){
            ans=-1;
            break;
        }
        S=E;
    }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d",&T);
    for(R i=0;i<T;i++){
        Solve();
    }
    return 0;
}