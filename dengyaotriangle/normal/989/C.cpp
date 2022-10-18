#include<bits/stdc++.h>

using namespace std;

const int maxn=55;
const int maxc=5;
const int c[6]={1,2,4,5,7,8};

char oa[maxn][maxn];
int v[maxc];

int main(){
	cin>>v[0]>>v[1]>>v[2]>>v[3];
	v[0]--;v[1]--;v[2]--;v[3]--;
	for(int i=0;i<4;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<50;k++){
				oa[i*10+j][k]='A'+i;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<47;k+=2){
				if(v[(i+1)%4]!=0){
					oa[i*10+c[j]][k+j%2]='A'+(i+1)%4;
					v[(i+1)%4]--;
				}
			}
		}
	}
	cout<<40<<' '<<50;
	for(int i=0;i<40;i++){
		cout<<endl;
		for(int j=0;j<50;j++) cout<<oa[i][j];
	}
}