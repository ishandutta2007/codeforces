#include<bits/stdc++.h>
using namespace std;
const int MAX = 150;
char flag [MAX][MAX];
int n,m;
int main(){
//	scanf("%d%d",&n,&m);
	cin>>n>>m;
	char useless;
	for (int i =0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>flag[i][j];
		}
//		scanf("%c",&useless);
	}
	if (n%3!=0&&m%3!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	bool succ1 = true,succ2 = true;
	if (n%3 == 0){
		int nn=n/3;
		char fir = flag[0][0];
		char sec = flag[nn][0];
		char thi = flag[nn*2][0];
		for (int i = 0;i<nn;i++){
			for (int j =0;j<m;j++){
				if (flag[i][j]!=fir){
					succ1 = false;
					break;
				}
			}
		}
		for (int i = nn;i<nn*2;i++){
			for (int j =0;j<m;j++){
				if (flag[i][j]!=sec){
					succ1 = false;
					break;
				}
			}
		}
		for (int i = nn*2;i<nn*3;i++){
			for (int j =0;j<m;j++){
				if (flag[i][j]!=thi){
					succ1 = false;
					break;
				}
			}
		}
//		cout<<succ1<<" "<<fir<<" "<<sec<<" "<<thi<<endl; 
		if (succ1&&fir!=sec&&fir!=thi&&sec!=thi){
			cout<<"YES"<<endl;
			return 0;
		}else{
			succ1 = false;
		}
	}
	if (m%3==0){
		int mm = m/3;
		char fir = flag[0][0];
		char sec = flag[0][mm];
		char thi = flag[0][mm*2];
		for (int i = 0;i<n;i++){
			for (int j = 0;j<mm;j++){
				if (flag[i][j]!=fir){
					succ2 = false;
					break;
				}
			}
		}
		for (int i = 0;i<n;i++){
			for (int j=mm;j<mm*2;j++){
				if(flag[i][j]!=sec){
					succ2 = false;
					break;
				}
			}
		}

		for (int i=0;i<n;i++){
			for (int j=mm*2;j<mm*3;j++){
				if (flag[i][j]!=thi){
					succ2 = false;
					break;
				}
			}
		}
//		cout<<succ2<<" "<<fir<<" "<<sec<<" "<<thi<<endl; 
		if (succ2&&fir!=sec&&fir!=thi&&sec!=thi){
			cout<<"YES"<<endl;
			return 0;
		}else{
			succ2 = false;
		}
	}
	cout<<"NO"<<endl;
	return 0; 
}