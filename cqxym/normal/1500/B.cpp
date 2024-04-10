#include<iostream>
using namespace std;
#define R register int
#define L long long
#define N 500000
int a[N],b[N],c[N],ref[N],pos[1000001];
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
int main(){
	//freopen("1.txt","r",stdin);
	int n,m,g;
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	g=Gcd(n,m);
	L k;
	scanf("%lld",&k);
	//cin>>k;
	for(R i=0;i!=n;i++){
		//cin>>a[i];
		scanf("%d",a+i);
	}
	for(R i=0;i!=m;i++){
		//cin>>b[i];
		scanf("%d",b+i);
	}
	//L l=k,mid,ans,r=30;
	L l=k,mid,ans,r=999999999999999999;
	n/=g;
	m/=g;
	int cur=0;
	for(R i=0;i!=m;i++){
		ref[cur]=i;
		cur=(cur+n)%m;
	}
	for(R i=0;i!=m;i++){
		for(R j=0;j!=g;j++){
			c[ref[i]*g+j]=b[i*g+j];
		}
	}
	for(R i=0;i!=1000001;i++){
		pos[i]=-1;
	}
	for(R i=0;i!=m*g;i++){
		pos[c[i]]=i;
	}
	L tot=(L)n*m*g;
	//cout<<l<<' '<<r<<endl;
	while(l<=r){
		//printf("L%lld %lld\n",l,r);
		mid=l+r>>1;
		L sum=0,t=mid%tot,q=mid/tot;
		for(R i=0;i!=n;i++){
			int st=ref[i%m];
			for(R j=0;j!=g;j++){
				int p=pos[a[i*g+j]],s=m;
				if(p!=-1&&p%g==j){
					s--;
				}else{
					p=-1;
				}
				//printf("K%d\n",p);
				sum+=q*s;
				//printf("T%lld\n",mid/tot*s);
				L left=t;
				int tem=left/(n*g);
				sum+=tem;
				//printf("F%d %lld\n",tem,left);
				if(left%(n*g)>j+i*g){
					//puts("O");
					sum++;
					tem++;
				}
				if(p!=-1){
					p/=g;
					if(p>=st){
						p-=st;
					}else{
						p=p+m-st;
					}
					if(tem>p){
						//printf("P%d %d\n",tem,p);
						sum--;
					}
				}
				//printf("%lld\n",sum);
			}
		}
		if(sum<k){
			l=mid+1;
		}else{
			ans=mid;
			r=mid-1;
		}
		//printf("M%lld %lld\n",mid,sum);
	}
	cout<<ans;
	return 0;
}
/*
4 5 20
2 3 1 4
3 4 5 1 2
*/