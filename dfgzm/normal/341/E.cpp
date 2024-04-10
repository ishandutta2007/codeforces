#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j,k,n,m,a[maxn];
priority_queue<pair<int,int> >Q;
struct node{
	int x,y;
}d[maxn*maxn];int cnt;
void move(int x,int y){
	a[x]-=a[y];a[y]*=2;
	d[++cnt]={x,y};
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i])Q.push({-a[i],i});
	}
	if(!Q.size() || Q.size()==1){
		puts("-1");
		return 0;
	}
	while(Q.size()!=2){
		int Min=Q.top().second;Q.pop();
		int Min2=Q.top().second;Q.pop();
		int Min3=Q.top().second;Q.pop();
		int last=cnt,w=a[Min],m=a[Min],m2=a[Min2],m3=a[Min3];
		//cout<<a[Min]<<' '<<a[Min2]<<' '<<a[Min3]<<endl;
        while(a[Min]<=a[Min2]){
            if(a[Min2]/a[Min]%2)move(Min2,Min);
            else move(Min3,Min);
        }
		if(a[Min])Q.push({-a[Min],Min});
		if(a[Min2])Q.push({-a[Min2],Min2});
		if(a[Min3])Q.push({-a[Min3],Min3});
		//cout<<a[Min]<<' '<<a[Min2]<<' '<<a[Min3]<<' '<<Q.size()<<endl;
	}cout<<cnt<<endl;
	for(i=1;i<=cnt;i++)printf("%d %d\n",d[i].y,d[i].x);
	return 0;
}