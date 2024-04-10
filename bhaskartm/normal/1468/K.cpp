#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string st;
		cin>>st;
		int n=st.size();
		int x[n+1];
		int y[n+1];
		x[0]=0;
		y[0]=0;
		for(int i=0; i<st.size(); i++){
			if(st[i]=='L'){
				x[i+1]=x[i]-1;
				y[i+1]=y[i];
			}
			else if(st[i]=='R'){
				x[i+1]=x[i]+1;
				y[i+1]=y[i];
			}
			else if(st[i]=='U'){
				y[i+1]=y[i]+1;
				x[i+1]=x[i];
			}
			else{
				y[i+1]=y[i]-1;
				x[i+1]=x[i];
			}
		}
		int ax=-10000000;
		int ay=-10000000;
		for(int i=1; i<=n; i++){
			int xx=x[i];
			int yy=y[i];
			if(xx==0 && yy==0){
				continue;
			}
			int xc=0;
			int yc=0;
			for(int j=0; j<st.size(); j++){
				if(st[j]=='L'){
					xc--;
					if(xc==xx && yc==yy){
						xc++;
					}
				}
				else if(st[j]=='R'){
					xc++;
					if(xc==xx && yc==yy){
						xc--;
					}
				}
				else if(st[j]=='U'){
					yc++;
					if(xc==xx && yc==yy){
						yc--;
					}
				}
				else{
					yc--;
					if(xc==xx && yc==yy){
						yc++;
					}
				}
			}
			
			if(xc==0 && yc==0){
				ax=xx;
				ay=yy;
				break;
			}
		}
		if(ax==-10000000){
			cout<<0<<" "<<0<<endl;
		}
		else{
			cout<<ax<<" "<<ay<<endl;
		}
	}
	return 0;
}