#include<bits/stdc++.h>
using namespace std;
char mapp[15][15];
int dx[4],dy[4];
int main(){
	dx[0]=0;dy[0]=1;
	dx[1]=-1;dy[1]=1;
	dx[2]=1;dy[2]=1;
	dx[3]=1;dy[3]=0;
	for (int i=0;i<10;i++){
		scanf("%s",mapp[i]);
	}
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			for (int k=0;k<4;k++){
				if (i+4*dx[k]>=0&&i+4*dx[k]<10&&j+4*dy[k]>=0&&j+4*dy[k]<10){
//					cout<<i<<" "<<j<<" "<<dx[k]<<" "<<dy[k]<<endl;
					int count = 0;
					for (int ii=i,jj=j;ii!=i+5*dx[k]||jj!=j+5*dy[k];ii+=dx[k],jj+=dy[k]){
//						cout<<ii<<" "<<jj<<"| "<<mapp[ii][jj]<<endl;;
						if (mapp[ii][jj]=='O'){
							break;
						}else if (mapp[ii][jj]=='X'){
							count++;
						}
					}
//					cout<<i<<" "<<j<<" "<<count<<endl;
					if (count==4&&mapp[i+4*dx[k]][j+4*dy[k]]!='O'){
						cout<<"YES"<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}