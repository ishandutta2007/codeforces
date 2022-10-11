#include<bits/stdc++.h>
using namespace std;
vector<long long>a,b,c,d;long long p1,p2,p3,n;
int main(){
	cin>>p1>>p2>>p3>>n;
	a.push_back(0);b.push_back(0);
	for(int i=0;i<n;i++){
		int I;string S;cin>>I>>S;
		if(S=="USB"){a.push_back(I);}
		if(S=="PS/2"){b.push_back(I);}
	}
	sort(a.begin(),a.end());sort(b.begin(),b.end());
	c.resize(a.size(),0);d.resize(b.size(),0);
	for(int i=1;i<(int)a.size();i++)c[i]=c[i-1]+a[i];
	for(int i=1;i<(int)b.size();i++)d[i]=d[i-1]+b[i];
	if(p3>=n){cout<<n<<' '<<c[a.size()-1]+d[b.size()-1]<<endl;return 0;}
	
	long long p4=a.size()-1,p5=b.size()-1;
	long long maxn=0,maxid=0;
	for(int i=0;i<=p3;i++){
		long long t1=p4-i,t2=p5-(p3-i);t1=min(t1,p1);t2=min(t2,p2);
		if(t1<0 || t2<0)continue;
		
		//cout<<t1<<' '<<t2<<endl;
		
		long long J1=p3+t1+t2;
		long long J2=c[t1+i]+d[t2+(p3-i)];
		if(J1>maxn || (J1==maxn && J2<maxid)){maxn=J1,maxid=J2;}
	}
	cout<<maxn<<' '<<maxid<<endl;
	return 0;
}