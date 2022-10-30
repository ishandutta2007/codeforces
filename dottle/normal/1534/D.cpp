#include<bits/stdc++.h>
const int N=2005;
using namespace std;

int a[N],cnt,p,n;
vector<int> b[2],f,t;
void psh(int x,int y){
	f.push_back(x),t.push_back(y);
}

int main(){
	scanf("%d",&n);
	printf("? 1\n"),fflush(stdout);
	scanf("%d",&a[1]); 
	for(int i=2;i<=n;i++)scanf("%d",&a[i]),b[a[i]&1].push_back(i);
	if(b[0].size()<b[1].size())p=0;else p=1;
	for(int i=0;i<b[p].size();i++){
		printf("? %d\n",b[p][i]),fflush(stdout);
		for(int j=1,x;j<=n;j++){
			scanf("%d",&x);
			if(x==1)psh(b[p][i],j);
		}
	}
	if(!p)
		for(int i=1;i<=n;i++)if(a[i]==1)
			psh(1,i);
	printf("!\n");
	for(int i=0;i<f.size();i++)
		printf("%d %d\n",f[i],t[i]);
}