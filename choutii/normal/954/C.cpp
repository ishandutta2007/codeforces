#include<bits/stdc++.h>
using namespace std;
int x,y,mx,n,st,a[200050];
int main(){
    cin>>n;
    bool F=1;
    cin>>a[1];mx=st=a[1];
    for(int i=2;i<=n;++i){
        cin>>a[i];
        if(a[i]!=a[i-1]+1 && a[i]!=a[i-1]-1){
            int t=abs(a[i]-a[i-1]);F=0;
            if(!t)return puts("NO"),0;
            if(!y)y=t;
            else {if(y!=t)return puts("NO"),0;}
            st=a[i];
        }
        mx=max(mx,a[i]);
        if(y)if((st-1)/y!=(a[i]-1)/y)return puts("NO"),0;
    }
    x=1000000000;
    if(F){
        puts("YES");
        cout<<x<<" "<<mx<<endl;
        return 0;
    }
    st=a[1];
    for(int i=2;i<=n;i++){
//    	if(abs(a[i]-a[i-1])==1&&(a[i]-1)/y!=(a[i-1]-1)/y)
  //  		return puts("NO"),0;
		if(abs(a[i]-a[i-1])!=1)
			st=a[i];
		if((a[i]-1)/y!=(st-1)/y)
			return puts("NO"), 0;
	}
    puts("YES");
    cout<<x<<" "<<y<<endl;
}