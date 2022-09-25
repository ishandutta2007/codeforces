#include <bits/stdc++.h>
#define rep(i,b,a) for(int i=b; i<a; i++)

using namespace std;
int n,x[25005],y[25005],a[25005],b[25005],c[25005],d;
double arr[25005],k1,k2,ans=1e30;
signed main(){
	cout << fixed << setprecision(12);
	cin >> n;
	rep(i,0,n) cin >> x[i] >> y[i] >> a[i] >> b[i] >> c[i];
	rep(i,0,n) arr[i]=sqrt(a[i]*a[i]+b[i]*b[i])/c[i];
	rep(i,0,n) rep(j,i+1,n){
	    d=a[i]*b[j]-a[j]*b[i];
	    if(d==0){
            if(a[i]*(y[j]-y[i])-b[i]*(x[j]-x[i])!=0) continue;
            if(a[i]*(x[j]-x[i])>0&&a[j]*(x[i]-x[j])>0) ans=min(ans,(x[j]-x[i])*arr[i]/a[i]*c[i]/(c[i]+c[j]));
            else if(a[i]*(x[j]-x[i])>0) ans=min(ans,(x[j]-x[i])*arr[i]/a[i]);
            else if(a[j]*(x[i]-x[j])>0) ans=min(ans,(x[i]-x[j])*arr[j]/a[j]);
            continue;
	    }
        k2=(b[i]*(x[j]-x[i])-a[i]*(y[j]-y[i]))/(double)d;
        k1=-(b[j]*(x[i]-x[j])-a[j]*(y[i]-y[j]))/(double)d;
        if(k1<0||k2<0) continue;
        ans=min(ans,max(k1*arr[i],k2*arr[j]));
	}
	if(ans>1e29) cout << "No show :(\n";
	else cout << ans << "\n";
	return 0;
}