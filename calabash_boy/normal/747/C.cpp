#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct str{
	long long task,finishtime;
	void init(){
		task=0;
		finishtime=0;
	}
}sever[105];
struct datastr{
	long long start,num,time;
}data[100005];
bool cmp(datastr a,datastr b){
	return a.start<b.start;
}
int main(){
	int n,q;
	cin>>n>>q;
	int startmax=0,timemax=0;
	for (int i=1;i<=q;i++){
		cin>>data[i].start>>data[i].num>>data[i].time;
		startmax=startmax>data[i].start?startmax:data[i].start;
		timemax=timemax>data[i].time?timemax:data[i].time;
		}
	for (int i=1;i<=n;i++){
		sever[i].init();
	}
	//sort(data+1,data+q,cmp);
//	for (int i=1;i<=q;i++){
//		cout<<data[i].start<<endl;
//	}
	int ptr=1;
	int cnt=n;
	for (long long i=1;i<=timemax+startmax;i++){
		if (ptr>q) return 0;
		for (int ii=1;ii<=n;ii++){
			if (sever[ii].finishtime==i){
				sever[ii].task=0;
				cnt++;
			}
		}
		if (data[ptr].start==i){
			if (data[ptr].num>cnt){
				cout<<"-1"<<endl;
			}else{
				long long  sum=0;
				for (int ii=1;ii<=n;ii++){
					
					if (sever[ii].task==0&&data[ptr].num){
						sever[ii].task=ptr;
				//	cout<<i<<':'<<ii<<endl;
						sum+=ii;
						sever[ii].finishtime=i+data[ptr].time;
						cnt--;
						data[ptr].num--;
						if (!data[ptr].num) break;
					}
				}
				cout<<sum<<endl;
			}
			ptr++;
		}
	}	
	return 0;
}