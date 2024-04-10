#include<bits/stdc++.h>
using namespace std;
const double eof=0.0000001;
const int N=50;
int n,m;
void out(int tp,double x,double y){
	if(tp==1)
		printf("%.13lf %.13lf\n",x,y);
	else
		printf("%.13lf %.13lf\n",y,x);
}
double solve(int tp){
	cout<<"? "<<4*N+2<<endl;
	for(int i=0;i<N;i++){
		out(tp,i+i,N+N);
		out(tp,i+i+1,N+N);
		out(tp,i+i+1,0);
		out(tp,i+i+2,0);
	}
	out(tp,N+N,-1);
	out(tp,0,-1);
	double val;cin>>val;val=1-val;
	vector<pair<double,double> >seg,que;
	for(int i=0;i<N;i++){
		if(!seg.size()||seg.back()!=make_pair(i+i+val,i+i+val+1))
			seg.push_back({i+i+val,i+i+val+1});
		if(val<eof||1-val<eof)
			continue;
		val=2-val;
		if(!seg.size()||seg.back()!=make_pair(i+i+val,i+i+val+1))
			seg.push_back({i+i+val,i+i+val+1});
		val=2-val;
	}
	for(int i=0;i<seg.size();i++){
		que.push_back(seg[i]);
		if(i&&que[i-1].second>que[i].first)
			swap(que[i].first,que[i-1].second);
		if(seg.size()==N)
			que[i].first+=eof,
			que[i].second-=eof;
	}
	cout<<"? "<<4*que.size()+4<<endl;
	double dis=eof*0.001,sum=0;
	for(int i=0;i<que.size();i++){
		sum+=dis;
		out(tp,que[i].first,0);
		out(tp,que[i].first,N+N);
		out(tp,que[i].first+sum,N+N);
		out(tp,que[i].first+sum,0);
	}
	out(tp,N+N+2,0);
	out(tp,N+N+2,-1);
	out(tp,-1,-1);
	out(tp,-1,0);
	double ans;
	cin>>ans;ans+=dis*0.1;
	int idx=ans/dis-1;
	return seg[idx].first;
}
int main(){
	cin>>n>>m;
	double x=solve(1),y=solve(-1);
	printf("! %.9lf %.9lf",x,y);
}