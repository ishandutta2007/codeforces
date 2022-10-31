#include<iostream>
using namespace std;
int main(){
	int dx[10],dy[10];
	char map[4][4];
	char temp;
	dx[1]=1;dy[1]=0;
	dx[2]=0;dy[2]=1;
	dx[3]=1;dy[3]=1;
	dx[4]=1;dy[4]=-1;
	dx[5]=-1;dy[5]=0;
	dx[6]=0;dy[6]=-1;
	dx[7]=-1;dy[7]=-1;
	dx[8]=-1;dy[8]=1; 
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++)
			cin>>map[i][j];
	}
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
		if (map[i][j]=='x')
			for (int k=1;k<=8;k++){
			int xx=i,yy=j;
	//		cout<<xx<<' '<<yy<<endl;
			bool flag=true;
			int empty=0;
			for (int h=1;h<=2;h++){
				xx+=dx[k];
				yy+=dy[k];
				if (xx>=4||yy>=4||xx<0||yy<0){
					flag=false;
					break;
				}else
					if (map[xx][yy]=='o'){
						flag=false;
						break;
				}else if (map[xx][yy]=='.'){
					empty++;					
				}
			}
			if (empty>=2){
				flag=false;
			}
			if (flag){
				cout<<"YES";
				return 0;
			}
		}
		cout<<"No";
		return 0;
}