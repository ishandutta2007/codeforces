    #include<bits/stdc++.h>
    using namespace std;
     
    const int maxn=1005;
     
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		char x[maxn];
    		int n;
    		cin>>x;
    		n=strlen(x);
    		sort(x,x+n);
    		if(x[0]==x[n-1]) cout<<-1<<endl;
    		else cout<<x<<endl;
    	}
    	return 0; 
    }