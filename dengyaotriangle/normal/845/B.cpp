#include<bits/stdc++.h>

using namespace std;

const int maxn=10;

char x[maxn];
int ans=6;

int main(){
	cin>>x;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				for(int a=0;a<10;a++){
					for(int b=0;b<10;b++){
						for(int c=0;c<10;c++){
							if(i+j+k==a+b+c){
								int chg=(int)(i+'0'!=x[0])+(int)(j+'0'!=x[1])+(int)(k+'0'!=x[2])+(int)(a+'0'!=x[3])+(int)(b+'0'!=x[4])+(int)(c+'0'!=x[5]);
								ans=min(ans,chg);
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}