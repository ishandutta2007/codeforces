#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int m,a[6],b[6];
vector<pii>ret;
bool even_;
int R,C,sta,stb;
vector<vector<int> >w[6];
void out(){
	for(int i=1;i<ret.size();i++){
		pii x=ret[i-1],y=ret[i];
		for(int j=0;j<6;j++)if(w[j][x.fi][x.se]!=w[j][y.fi][y.se]){
			if(w[j][x.fi][x.se]<w[j][y.fi][y.se])printf("inc ");
			else printf("dec ");
			printf("%d\n",j+1);
			break;
		}
	}
}
void init(){
	R=a[0],C=1;
	for(int i=1;i<6;i++)C*=a[i];
	for(int i=0;i<6;i++){
		w[i].resize(R+1);
		for(int j=1;j<=R;j++)w[i][j].resize(C+1);
	}
	for(int i=1;i<=a[5];++i)
		for(int j=1;j<=a[4];++j)
			for(int k=1;k<=a[3];++k)
				for(int p=1;p<=a[2];++p)
					for(int q=1;q<=a[1];++q){
						int y=(i-1)*a[4]*a[3]*a[2]*a[1]+(j-1)*a[3]*a[2]*a[1]+(k-1)*a[2]*a[1]+(p-1)*a[1]+q; 
						for(int x=1;x<=a[0];++x){
							w[0][x][y]=x;
							w[1][x][y]=((i-1)*a[4]*a[3]*a[2]+(j-1)*a[3]*a[2]+(k-1)*a[2]+p)&1?q:a[1]-q+1;
							w[2][x][y]=((i-1)*a[4]*a[3]+(j-1)*a[3]+k)&1?p:a[2]-p+1;
							w[3][x][y]=((i-1)*a[4]+j)&1?k:a[3]-k+1;
							w[4][x][y]=i&1?j:a[4]-j+1;
							w[5][x][y]=i; 
							if(w[0][x][y]==b[0]&&w[1][x][y]==b[1]&&w[2][x][y]==b[2]&&w[3][x][y]==b[3]&&w[4][x][y]==b[4]&&w[5][x][y]==b[5])sta=x,stb=y;
						}
					}
}
void Cycle(){
	vector<pii>v;
	if(R&1){
		for(int i=1;i<R;i++)v.push_back(mkp(i,1));
		for(int i=1;i<=C;i++)v.push_back(mkp(R,i));
		for(int i=R-1;i;i--)v.push_back(mkp(i,C));
		for(int i=C-1;i>1;i--){
			if(i&1)for(int j=1;j<R;j++)v.push_back(mkp(j,i));
			else for(int j=R-1;j;j--)v.push_back(mkp(j,i));
		}
	}else{
		for(int i=1;i<C;i++)v.push_back(mkp(1,i));
		for(int i=1;i<=R;i++)v.push_back(mkp(i,C));
		for(int i=C-1;i;i--)v.push_back(mkp(R,i));
		for(int i=R-1;i>1;i--){
			if(i&1)for(int j=1;j<C;j++)v.push_back(mkp(i,j));
			else for(int j=C-1;j;j--)v.push_back(mkp(i,j));
		}
	}
	for(int i=0;i<R*C;i++)if(v[i]==mkp(sta,stb)){
		ret.push_back(v[i]);
		for(int j=1;j<=R*C;j++)ret.push_back(v[(i+j)%(R*C)]);
		return;
	}
}
void Path(){
	if(sta==1){
		for(int i=1;i<R;i++){
			if(i&1)for(int j=stb;j;j--)ret.push_back(mkp(i,j));
			else for(int j=1;j<=stb;j++)ret.push_back(mkp(i,j));
		}
		for(int i=stb+1;i<=C;i++){
			if(i&1)for(int j=1;j<R;j++)ret.push_back(mkp(j,i));
			else for(int j=R-1;j;j--)ret.push_back(mkp(j,i));
		}
		for(int i=C;i;i--)ret.push_back(mkp(R,i));
		return;
	}
	if(sta==R){
		for(int i=R;i>1;i--){
			if(i&1)for(int j=stb;j;j--)ret.push_back(mkp(i,j));
			else for(int j=1;j<=stb;j++)ret.push_back(mkp(i,j));
		}
		for(int i=stb+1;i<=C;i++){
			if(i&1)for(int j=R;j>1;j--)ret.push_back(mkp(j,i));
			else for(int j=2;j<=R;j++)ret.push_back(mkp(j,i));
		}
		for(int i=C;i;i--)ret.push_back(mkp(1,i));
		return;
	}
	if(stb==1){
		for(int i=1;i<C;i++){
			if(i&1)for(int j=sta;j;j--)ret.push_back(mkp(j,i));
			else for(int j=1;j<=sta;j++)ret.push_back(mkp(j,i));
		}
		for(int i=sta+1;i<=R;i++){
			if(i&1)for(int j=1;j<C;j++)ret.push_back(mkp(i,j));
			else for(int j=C-1;j;j--)ret.push_back(mkp(i,j));
		}
		for(int i=R;i;i--)ret.push_back(mkp(i,C));
		return;
	}
	if(stb==C){
		for(int i=C;i>1;i--){
			if(i&1)for(int j=sta;j;j--)ret.push_back(mkp(j,i));
			else for(int j=1;j<=sta;j++)ret.push_back(mkp(j,i));
		}
		for(int i=sta+1;i<=R;i++){
			if(i&1)for(int j=C;j>1;j--)ret.push_back(mkp(i,j));
			else for(int j=2;j<=C;j++)ret.push_back(mkp(i,j));
		}
		for(int i=R;i;i--)ret.push_back(mkp(i,1));
		return;
	}
	if(sta&1){
		for(int i=sta;i;i--)ret.push_back(mkp(i,stb));
		for(int i=1;i<=sta;i++){
			if(i&1)for(int j=stb-1;j;j--)ret.push_back(mkp(i,j));
			else for(int j=1;j<stb;j++)ret.push_back(mkp(i,j));
		}
		for(int i=1;i<=stb;i++){
			if(i&1)for(int j=sta+1;j<=R;j++)ret.push_back(mkp(j,i));
			else for(int j=R;j>sta;j--)ret.push_back(mkp(j,i));
		}
		for(int i=stb+1;i<=C;i++){
			if(i&1)for(int j=1;j<=R;j++)ret.push_back(mkp(j,i));
			else for(int j=R;j;j--)ret.push_back(mkp(j,i));
		}
		return;
	}
	for(int i=stb;i;i--){
		if(i&1)for(int j=1;j<=sta;j++)ret.push_back(mkp(j,i));
		else for(int j=sta;j;j--)ret.push_back(mkp(j,i));
	}
	for(int i=sta+1;i<=R;i++){
		if(i&1)for(int j=1;j<=stb;j++)ret.push_back(mkp(i,j));
		else for(int j=stb;j;j--)ret.push_back(mkp(i,j));
	}
	for(int i=stb+1;i<=C;i++){
		if(i&1)for(int j=R;j;j--)ret.push_back(mkp(j,i));
		else for(int j=1;j<=R;j++)ret.push_back(mkp(j,i)); 
	}
}
int main(){
	scanf("%d",&m);
	for(int i=0;i<m;i++)cin>>a[i],even_|=!(a[i]&1);
	for(int i=0;i<m;i++)cin>>b[i];
	for(int i=m;i<6;i++)a[i]=b[i]=1;
	if(m==1){
		if(a[0]==2){
			puts("Cycle");
			if(b[0]==1)puts("inc 1"),puts("dec 1");
			else puts("dec 1"),puts("inc 1");
		}else{
			if(b[0]==1){
				puts("Path");
				for(int i=1;i<a[0];i++)puts("inc 1");
			}else if(b[0]==a[0]){
				puts("Path");
				for(int i=1;i<a[0];i++)puts("dec 1");
			}else puts("No");
		}
		return 0;
	}
	init();
	if(even_){
		puts("Cycle");
		Cycle();
	}else{
		int ok=0;
		for(int i=0;i<m;i++)ok^=(b[i]-1);
		if(ok&1){
			puts("No");
			return 0;
		}
		puts("Path");
		Path();
	}
	out();
}