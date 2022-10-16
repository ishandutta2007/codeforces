#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int n,now,id,q[10005],ans[10005];
int ask(int x,int y){
	cout<<'?'<<' '<<q[x]<<' '<<q[y]<<endl;
	int ans;
	cin>>ans;
	return ans;
}
int val(int id){
	int ans=-1;
	for (int i=1;i<=20;i++){
		int QwQ=rand()%n+1;
		while(QwQ==id)QwQ=rand()%n+1;
		if (ans==-1)ans=ask(id,QwQ);
		else ans&=ask(id,QwQ);
	}
	return ans;
}
int main(){
	srand(time(NULL));
	cin>>n;
	for (int i=1;i<=n;i++)q[i]=i;
	for (int i=1;i<=1000000;i++){
		int x=rand()%n+1,y=rand()%n+1;
		while(x==y)x=rand()%n+1,y=rand()%n+1;
		swap(q[x],q[y]);
	}
	id=1,now=val(1);
	for (int i=2;i<=n&&now>0;i++)
		if (ask(id,i)==now)id=i,now=val(i);
	for (int i=1;i<=n;i++){
		if (i==id)ans[q[i]]=0;
		else ans[q[i]]=ask(i,id);
	}
	cout<<'!'<<' ';
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}