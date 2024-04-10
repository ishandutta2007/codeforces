#include <bits/stdc++.h>
using namespace std;
long long int N=998244353;
 
 
long long  po(long long int x, long long  int y)  
{  
    long long int res = 1;     // Initialize result  
 
    x = x % N; // Update x if it is more than or  
                // equal to p 
 
    if (x == 0) return 0; // In case x is divisible by p; 
 
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % N;  
 
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % N;  
    }  
    return res;  
}  
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	long long int fac[200005];
	long long int inv[200005];
	fac[0]=1;
	inv[0]=1;
	for(int i=1; i<200005; i++){
		fac[i]=(fac[i-1]*i)%N;
		inv[i]=po(fac[i], N-2)%N;
		
	}
 
	cin>>n>>k;
	if(k>(n-1)){
		cout<<0<<endl;
		return 0;
	}
	if(k==0){
		cout<<fac[n]<<endl;
		return 0;
	}
	else{
		long long int ans=2;
		
		ans=(ans*fac[n])%N;
		
		ans=(ans*inv[k])%N;
		
		ans=(ans*inv[n-k])%N;
		
		long long int ans2=0;
		for(int i=0; i<n-k; i++){
			long long int val=1;
			val=(val*fac[n-k])%N;
			val=(val*inv[i])%N;
			val=(val*inv[n-k-i])%N;
			val=(val*(po(n-k-i, n)))%N;
			if(i%2==1){
				val=-val;
				val=(val+N)%N;
			}
			
			ans2=(ans2+val)%N;
		}
		
		cout<<(ans2*ans)%N<<endl;
	}
 
	return 0;
}