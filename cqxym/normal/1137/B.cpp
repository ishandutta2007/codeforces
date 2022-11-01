#include<iostream>
using namespace std;
#define R register int
int f[500000],ct[2];
inline char Get(const short p){
	int q;
	if(ct[p]==0){
		q=p^1;
	}else{
		q=p;
	}
	ct[q]--;
	return q+'0';
}
int main(){
	string s,t;
	cin>>s>>t;
	int l1=s.length(),l2=t.length();
	f[0]=-1;
	for(R i=0;i!=l1;i++){
		ct[s[i]-'0']++;
	}
	for (R i=1;i!=l2;i++){
	    int j=f[i-1];
	    while(t[j+1]!=t[i]&&j>=0){
	        j=f[j];
		}
	    if(t[j+1]==t[i]){
	        f[i]=j+1;
		}else{
	        f[i]=-1;
		}
	}
	const int d=f[l2-1]+1;
	int p=0;
	for(R i=0;i!=l1;i++){
		int tem=t[p]-'0',T;
		T=Get(tem);
		putchar(T);
		p++;
		if(p==l2){
			p=d;
		}
	}
	return 0;
}