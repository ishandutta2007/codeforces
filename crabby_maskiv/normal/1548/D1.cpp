#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e3+5;
int n,m;
int x[N],y[N];
int c[4][4];
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++) cin>>x[i]>>y[i];
	ll answ=0;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			if(i!=k){
				x[i]-=x[k];
				y[i]-=y[k];
			}
		}
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++){
			if(i==k) continue;
			c[(x[i]%4+4)%4][(y[i]%4+4)%4]++;
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				for(int a=0;a<4;a++){
					for(int b=0;b<4;b++){
					//	ll t=answ;
						if((i==a)&&(j==b)){
							answ+=c[i][j]*(c[i][j]-1);
							continue;
						}
						int f1=(i==0||j==0),f2=(a==0||b==0),f3=(i==a||j==b);
						if(f1^f2^f3)
							answ+=c[i][j]*c[a][b];
//						if(answ>t){
//							cout<<i<<" "<<j<<" "<<a<<" "<<b<<", "<<answ-t<<" "<<k<<endl;
//						}
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			if(i!=k){
				x[i]+=x[k];
				y[i]+=y[k];
			}
		}
	}
	cout<<answ/6;
	return 0;
}