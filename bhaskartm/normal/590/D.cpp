#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=155;
int n, k, sw;
int arr[N];
int dpl1[77][5005];
int dpl2[77][5005];
int dpr1[77][5005];
int dpr2[77][5005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k>>sw;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	for(int i=0; i<77; i++){
		for(int j=0; j<5005; j++){
			dpl1[i][j]=-1e9;
			dpl2[i][j]=-1e9;
			dpr1[i][j]=+1e9;
			dpr2[i][j]=+1e9;
		}
	}
	if(k==n){
		int ans=0;
		for(int i=1; i<=n; i++){
			ans+=arr[i];
		}
		cout<<ans;
		return 0;
	}
	dpl1[0][0]=0;
	
	for(int i=1; i<=k; i++){
		for(int j=0; j<=75; j++){
			for(int l=0; l<5005; l++){
				dpl2[j][l]=max(dpl1[j][l],dpl2[j][l]);
				int nsw=l-j+(k-i);
				if(nsw<5005){
					dpl2[j+1][nsw]=max(dpl2[j+1][nsw], dpl1[j][l]+arr[i]);
				}
			}
		}
		for(int j=0; j<=75; j++){
			for(int l=0; l<5005; l++){
				dpl1[j][l]=dpl2[j][l];
			}
		}
	}
	dpr1[0][0]=0;
	for(int i=n; i>k; i--){
		for(int j=0; j<=75; j++){
			for(int l=0; l<5005; l++){
				dpr2[j][l]=min(dpr1[j][l], dpr2[j][l]);
				int nsw=l-j+(i-(k+1));
				if(nsw<5005){
					dpr2[j+1][nsw]=min(dpr2[j+1][nsw], dpr1[j][l]+arr[i]);
				}
			}
		}
		for(int j=0; j<=75; j++){
			for(int l=0; l<5005; l++){
				dpr1[j][l]=dpr2[j][l];
			}
		}
	}
	
	int tot=0;
	
	for(int i=1; i<=k; i++){
		tot+=arr[i];
	}
	int maxi=0;
	int l1=k;
	int l2=n-k;
	int l3=min(l1, l2);
	
	for(int i=1; i<=l3; i++){
		for(int j1=0; j1<=i*(l1-i); j1++){
			for(int j2=0; j2<=i*(l2-i); j2++){
				if(j1+j2+i*i<=sw){
					maxi=max(maxi, dpl1[i][j1]-dpr1[i][j2]);
				}
			}
		}
	}
	
	cout<<tot-maxi<<endl;
	
	
	return 0;
}