#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

char x[maxn];
char o[maxn];
int lst[100];
int cnt[100];
long long sum;
int lst2[100];
int l;
long long ans=maxn+maxn;
int a0=-1,a1=-1;
int f0,f1;
int vldtm;
int main(){
	cin>>x;
	while(x[l])l++;
	for(int i=0;i<l;i++){
		sum+=x[i]-'0';
		lst2[x[i]-'0']=lst[x[i]-'0'];
		lst[x[i]-'0']=i;
		cnt[x[i]-'0']++;
	}
	sum=sum%3;
	vldtm=l-cnt[0];
	if(sum==0){
		cout<<x;
		return 0;
	}
	if(l==1){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<l;i++){
		if(x[i]!='0') break;
		f0++;
	}
	for(int i=2;i<l;i++){
		if(x[i]!='0') break;
		f1++;
	}
	for(int i=1;i<10;i++){
		for(int j=i;j<10;j++){
			if(i==j){
				if(cnt[i]>=2&&l>2&&(i+j)%3==sum){
					if(lst2[i]==0&&lst[i]==1&&2<vldtm){
						if(ans>2+f1){
							ans=2+f1;a0=i;a1=j;
						}
					}else if(lst2[i]==0&&2<vldtm){
						if(ans>2+f0){
							ans=2+f0;a0=i;a1=j;
						}
					}else{
						if(ans>2&&2<vldtm){
							ans=2;a0=i;a1=j;
						}
					}
				}
			}else{
				if(cnt[i]>=1&&cnt[j]>=1&&l>2&&(i+j)%3==sum){
					if(lst[i]==1&&lst[j]==0&&2<vldtm){
						if(ans>2+f1){
							ans=2+f1;a0=i;a1=j;
						}
					}else if(lst[j]==1&&lst[i]==0&&2<vldtm){
						if(ans>2+f1){
							ans=2+f1;a0=i;a1=j;
						}
					}else if(lst[i]==0&&2<vldtm){
						if(ans>2+f0){
							ans=2+f0;a0=i;a1=j;
						}
					}else if(lst[j]==0&&2<vldtm){
						if(ans>2+f0){
							ans=2+f0;a0=i;a1=j;
						}
					}else{
						if(ans>2&&2<vldtm){
							ans=2;a0=i;a1=j;
						}
					}
				}
			}
			if(cnt[i]>=1&&l>1&&(i)%3==sum){
				if(lst[i]==0){
					if(ans>1+f0&&1<vldtm){
						ans=1+f0;a0=i;a1=0;
					}
				}else{
					if(ans>1&&1<vldtm){
						ans=1;a0=i;a1=0;
					}
				}
			}
		}
	}
	bool is0ans=0;
	for(int i=0;i<l;i++) if(x[i]=='0') is0ans=1;
	if(is0ans){
		if(ans>(l-1)){
			ans=l-1;a0=0;a1=0;
		}
	}
	if(a0==-1||ans==l){
		cout<<-1;
		return 0;
	}
	if(a0==0){
		cout<<0;
		return 0;
	}
	if(a1==0){
		for(int i=0;i<l;i++){
			o[i]=x[i];
		}
		for(int i=lst[a0]+1;i<l;i++){
			o[i-1]=o[i];
		}
		bool gt=0;
		for(int i=0;i<l-1;i++){
			if(o[i]!='0')  gt=1;
			if(gt) cout<<o[i];
		}
	}else{
		for(int i=0;i<l;i++){
			o[i]=x[i];
		}
		int v2=lst[a1];
		if(a0==a1){
			v2=lst2[a0];
		}
		if(lst[a0]<v2){
			for(int i=v2+1;i<l;i++){
				o[i-1]=o[i];
			}
			for(int i=lst[a0]+1;i<l-1;i++){
				o[i-1]=o[i];
			}
		}else{
			for(int i=lst[a0]+1;i<l;i++){
				o[i-1]=o[i];
			}
			for(int i=v2+1;i<l-1;i++){
				o[i-1]=o[i];
			}
		}
		bool gt=0;
		for(int i=0;i<l-2;i++){
			if(o[i]!='0')  gt=1;
			if(gt) cout<<o[i];
		}
	}
	return 0;
}