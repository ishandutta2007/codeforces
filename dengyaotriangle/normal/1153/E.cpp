#include<bits/stdc++.h>

using namespace std;

int que[1004];
int fp[3];
int df[5];
bool gq(int a,int b,int c,int d){
	cout<<"? "<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	fflush(stdout);
	int ans;
	cin>>ans;
	return ans%2;
}
int main(){
	srand(time(0));
	srand(rand()+19260817);
	srand((rand()-19260817)<<8);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) que[i]=i;
	random_shuffle(que+1,que+1+n);
	int gt=0;
	for(int ii=1;ii<=n;ii++){
		int i=que[ii];
		if(gq(i,1,i,n)){
			fp[++gt]=i;
			if(gt==2)break;
		}
	}
	if(gt){
		for(int dd=1;dd<=2;dd++){
			int l=1,r=n;
			while((r-l)>2){
				int m=(l+r)/2;
				if(gq(fp[dd],l,fp[dd],m)){
					r=m;
				}else{
					l=m+1;
				}
			}
			for(int i=l;i<=r;i++){
				if(gq(fp[dd],i,fp[dd],i)){
					df[dd*2-1]=fp[dd];
					df[dd*2]=i;
				}
			}
		}
		cout<<"! "<<df[1]<<' '<<df[2]<<' '<<df[3]<<' '<<df[4];
		fflush(stdout);
		return 0;
	}
	random_shuffle(que+1,que+1+n);
	for(int ii=1;ii<=n;ii++){
		int i=que[ii];
		if(gq(1,i,n,i)){
			fp[++gt]=i;
			if(gt==2)break;
		}
	}
	for(int dd=1;dd<=2;dd++){
		int l=1,r=n;
		while((r-l)>2){
			int m=(l+r)/2;
				if(gq(l,fp[dd],m,fp[dd])){
				r=m;
			}else{
				l=m+1;
			}
		}
		for(int i=l;i<=r;i++){
			if(gq(i,fp[dd],i,fp[dd])){
				df[dd*2-1]=i;
				df[dd*2]=fp[dd];
			}
		}
		
	}
	cout<<"! "<<df[1]<<' '<<df[2]<<' '<<df[3]<<' '<<df[4];
	fflush(stdout);
	return 0;
	
}