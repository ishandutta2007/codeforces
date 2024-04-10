#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    sc(t);
    while(t--){
    	int n;
    	string a;
    	sc(n,a);
    	bool done=false;
    	for(int i=0;i<=9;i++){
    		int last=0;
    		int lastloc=-1;
    		bool work=true;
    		int colour[n];
    		for(int j=0;j<n;j++){
    			if((a[j]-'0')<i){
    				if((a[j]-'0')<last){
    					work=false;
    					break;
    				}
    				colour[j]=1;
    				last=(a[j]-'0');
    				lastloc=j;
    			}
    		}
    		if(!work)continue;
    		int last2=0;
    		int earlyloc=n;
		    for(int j=0;j<n;j++){
			    if((a[j]-'0')>i){
			    	earlyloc=min(earlyloc,j);
				    if((a[j]-'0')<last2){
					    work=false;
					    break;
				    }
				    colour[j]=2;
				    last2=(a[j]-'0');
			    }
		    }
		    if(!work)continue;
		    for(int j=earlyloc+1;j<=lastloc;j++){
		    	if((a[j]-'0')==i){
		    		work=false;
		    		break;
		    	}
		    }
		    if(!work)continue;
		    done=true;
		    for(int j=0;j<earlyloc;j++){
			    if((a[j]-'0')==i)colour[j]=2;
		    }
		    for(int j=lastloc+1;j<n;j++){
			    if((a[j]-'0')==i)colour[j]=1;
		    }
		    for(int i=0;i<n;i++){
		    	pr(colour[i]);
		    }
		    pr("\n");
		    break;
    	}
    	if(!done)pr("-\n");
    }
    return 0;
}