#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int x[maxn];
int chg[maxn];
int n;

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	if(n<=2){
		cout<<0;
		return 0;
	}
	int stdcg=x[1]-x[0];
	int minn=n+2;
	for(int i=x[0]-3;i<=x[0]+3;i++){
		for(int j=stdcg-5;j<=stdcg+5;j++){
			int ca=0;
			int stp=j,ini=i;
			//cout<<ini<<','<<stp<<':';
			for(int k=0;k<n;k++){
				//cout<<x[k]<<'/'<<ini<<'-';
				if(x[k]-ini==1||x[k]-ini==0-1) ca++;
				else if(x[k]!=ini){
					ca=-1;
					break;
				}
				ini+=stp;
			}
			//cout<<';'<<minn<<','<<ca<<endl;
			if(ca==-1) continue;
			minn=min(minn,ca);
		}
	}
	if(minn==n+2){
		cout<<-1;
		return 0;
	}
	cout<<minn;
	return 0;
}