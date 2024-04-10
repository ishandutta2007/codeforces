    #include<bits/stdc++.h>
     
    using namespace std;
    #define ll long long
     
    const int N = 233;
    int Ans, n;
    ll ax, ay, bx, by, xx, yy, t, x[N], y[N];
    int main() {
    	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", x, y, &ax, &ay, &bx, &by, &xx, &yy, &t);
    	while(x[n]<=2e16 && y[n]<=2e16) ++n, x[n]=ax*x[n-1]+bx, y[n]=ay*y[n-1]+by;
    	for(int i=0; i<=n; ++i) if(abs(xx-x[i])+abs(yy-y[i])<=t){
    		ll tt=t-(abs(xx-x[i])+abs(yy-y[i]));
    		int ans=1;
    		for(int j=i-1; j>=0; --j){
    			tt-=abs(x[j]-x[j+1])+abs(y[j]-y[j+1]);
    			if(tt<0) break; else ++ans;
    		}
    		Ans=max(Ans, ans);
    		tt=t-(abs(xx-x[i])+abs(yy-y[i]));
    		ans=1;
    		for(int j=i+1; j<=n; ++j){
    			tt-=abs(x[j]-x[j-1])+abs(y[j]-y[j-1]);
    			if(tt<0) break; else ++ans;
    		}
    		Ans=max(Ans, ans);
    	}
    	printf("%d\n", Ans);
    	return 0;
    }