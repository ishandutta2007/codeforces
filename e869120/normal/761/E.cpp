#include<bits/stdc++.h>
using namespace std;
vector<int>x[31];
long long n,a,b,c,d,g[31],y[31],power[31];bool used[31];
int main(){
	cin>>n;for(int i=0;i<n-1;i++){cin>>a>>b;a--;b--;x[a].push_back(b);x[b].push_back(a);}
	power[0]=1;for(int i=1;i<31;i++)power[i]=power[i-1]*3;
	for(int i=0;i<n;i++){
		if(x[i].size()>=5){cout<<"NO"<<endl;return 0;}
		if(x[i].size()==4){d=i;c++;}
	}
	queue<tuple<int,int,int>>Q;Q.push(make_tuple(d,-3,0));used[d]=true;
	long long dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
	
	while(!Q.empty()){
		int a1=get<0>(Q.front()),a2=get<1>(Q.front()),a3=get<2>(Q.front());Q.pop();
		int D=0;
		for(int i=0;i<4;i++){
			if(D>=(int)x[a1].size())continue;
			while(true){
				int to=x[a1][D];if(used[to]==false)break;
				if(used[to]==true){D++;}
				if(D==(int)x[a1].size())break;
			}
			if(D>=(int)x[a1].size())continue;
			if(a2>=0 && (2+a2)%4==i)continue;
			int to=x[a1][D];
			D++;
			long long fx=g[a1]+dx[i]*power[n-a3],fy=y[a1]+dy[i]*power[n-a3];
			g[to]=fx;y[to]=fy;Q.push(make_tuple(to,i,a3+1));
			used[to]=true;
		}
		while(D<(int)x[a1].size()){
			int to=x[a1][D];if(used[to]==false)break;
			if(used[to]==true){D++;}
			if(D==(int)x[a1].size())break;
		}
		if(D<(int)x[a1].size()){cout<<"NO"<<endl;return 0;}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)cout<<g[i]<<' '<<y[i]<<endl;
	return 0;
}