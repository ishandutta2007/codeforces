#include<bits/stdc++.h>
using namespace std;
const int maxn = 2050;
const int N = 5e6+1000;
int x[maxn],y[maxn];
bool ex [N];
int n;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",x+i);
		ex[x[i]] =true;
	}
	for (int i=0;i<n;i++){
		scanf("%d",y+i);
		ex[y[i]] =true;
	}
	int cnt=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if ((x[i]^y[j])<N&&ex[x[i]^y[j]]){
				cnt++;
			}
		}
	}
//	cout<<cnt<<endl;
	if (!(cnt&1)){
		printf("Karen\n");
	}else{
		printf("Koyomi\n");
	}
	return 0;
}