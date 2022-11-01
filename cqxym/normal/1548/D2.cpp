#include<iostream>
using namespace std;
#define R register int
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
int px[6000],py[6000],ct[4][4][4],d[4][4];
int main(){
	for(R i=1;i!=4;i++){
		for(R j=1;j!=4;j++){
			d[i][j]=Gcd(i,j);
		}
	}
	int n,x,y,g;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>px[i]>>py[i];
	}
	long long ans0=0,ans1=0;
	for(R i=0;i!=n;i++){
		for(R j=0;j!=4;j++){
			for(R k=0;k!=4;k++){
				for(R l=0;l!=4;l++){
					ct[j][k][l]=0;
				}
			}
		}
		for(R j=0;j!=n;j++){
			if(i!=j){
				x=px[j]-px[i];
				y=py[j]-py[i];
				g=Gcd(x<0?-x:x,y<0?-y:y);
				ct[x&3][y&3][g&3]++;
			}
		}
		for(R j1=0;j1!=4;j1++){
			for(R k1=0;k1!=4;k1++){
				for(R l1=0;l1!=4;l1++){
					for(R j2=0;j2!=4;j2++){
						for(R k2=0;k2!=4;k2++){
							for(R l2=0;l2!=4;l2++){
								if(((j1^j2)&1)==0&&((k1^k2)&1)==0&&((l1^l2)&1)==0){
									int b=(j1==j2&&k1==k2?0:2)+l1+l2,s=j1*k2-k1*j2;
									if((b-s&3)==0){
										int w=ct[j1][k1][l1]*(ct[j2][k2][l2]-(j1==j2&&k1==k2&&l1==l2?1:0));
										long long&res=(l1&1)==0?ans0:ans1;
										res+=w;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ans0/6+(ans1>>1);
	return 0;
}