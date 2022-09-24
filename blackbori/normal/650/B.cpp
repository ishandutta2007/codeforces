#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

#define ld I64d

using namespace std;

typedef long long LL;

LL D[505050],L[505050],R[505050];
string s;
int n;
LL a,b,t,k,ans;

long long mx(LL ma,LL mb)
{
	return ma<mb?mb:ma;
}

long long mn(LL ma,LL mb)
{
	return ma>mb?mb:ma;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin.sync_with_stdio(false);
	
	int i,c;
	
	cin>>n;
	cin>>a>>b>>t;
	cin>>s;
	
	for(i=0;i<n;i++){
		if(s[i]=='w') D[i]=b+1;
		else D[i]=1;
	}
	b=D[0], D[0]=0;
	L[0]=R[0]=D[0];
	for(i=1;i<n;i++){
		L[i] = L[i-1]+D[n-i]+a;
	}
	for(i=1;i<n;i++){
		R[i] = R[i-1]+D[i]+a;
	}
	
//	for(i=0;i<n;i++) printf("%ld %ld %ld\n",D[i],L[i],R[i]);
//	printf("\n");
	
	for(i=0;i<n;i++){
		k=t-(R[i]+a*i)-b;
		if(k>=0){
			c=upper_bound(L,L+n,k)-L-1;
			//printf("%d %ld %d %ld\n",i,k,c,L[c]);
			ans = mx(ans,i+c+1);
		}
	}
	
	for(i=0;i<n;i++){
		k=t-(L[i]+a*i)-b;
		if(k>=0){
			c=upper_bound(R,R+n,k)-R-1;
			//printf("%d %ld %d %ld\n",i,k,c,R[c]);
			ans = mx(ans,i+c+1);
		}
	}
	
	printf("%ld\n",mn(ans,n));
	
	return 0;
}