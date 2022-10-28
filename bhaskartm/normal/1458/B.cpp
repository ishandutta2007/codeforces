#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double

const int N=105;
int n;
int a[N];
int b[N];

int dp1[105][10005]; 
int dp2[105][10005];

 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	int sum=0;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>b[i];
		sum+=b[i];
	}
	
	for(int i=0; i<105; i++){
		for(int j=0; j<10005; j++){
			dp1[i][j]=-1e9;
			dp2[i][j]=-1e9;
		}
	}
	
	dp1[0][0]=0;
	dp2[0][0]=0;
	
	for(int i=1; i<=n; i++){
		for(int num=0; num<i; num++){
			for(int sb=0; sb<10005; sb++){
				dp1[num][sb]=max(dp1[num][sb], dp2[num][sb]);
				if(sb+b[i]<10005){
					dp1[num+1][sb+b[i]]=max(dp1[num+1][sb+b[i]], dp2[num][sb]+a[i]);
				}
			}
		}
		for(int num=0; num<=i; num++){
			for(int sb=0; sb<10005; sb++){
				dp2[num][sb]=dp1[num][sb];
			}
		}
	}
	
	
	
	
	
	for(int i=1; i<=n; i++){
		T maxi=0;
		for(int j=0; j<10005; j++){
			
			T val=dp1[i][j];
			
			T rem=sum-j;
			maxi=max(maxi, j+min(val-j, rem/2));
		}
		cout<<fixed<<setprecision(9)<<maxi<<" ";
	}
	cout<<endl;
	
	
	
	return 0;
}