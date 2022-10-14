#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	int minto=0;
    	int maxbo=0;
    	int minle=0;
    	int maxri=0;
    	int x=0;
    	int y=0;
    	for(int i=0;i<s.size();i++){
    		if(s[i]=='W'){
    			x-=1;
    			minto=min(minto,x);
    		}
		    if(s[i]=='S'){
			    x+=1;
			    maxbo=max(maxbo,x);
		    }
		    if(s[i]=='A'){
			    y-=1;
			    minle=min(minle,y);
		    }
		    if(s[i]=='D'){
			    y+=1;
			    maxri=max(maxri,y);
		    }
    	}
    	bool botable=true;
    	bool reach=false;
    	x=0;
    	y=0;
    	for(int i=0;i<s.size();i++){
		    if(x==maxbo)reach=true;
		    if(reach&&x==minto)botable=false;
		    if(s[i]=='W'){
			    x-=1;
		    }
		    if(s[i]=='S'){
			    x+=1;
		    }
		    if(s[i]=='A'){
			    y-=1;
		    }
		    if(s[i]=='D'){
			    y+=1;
		    }

    	}
	    if(x==maxbo)reach=true;
	    if(reach&&x==minto)botable=false;
    	if(x==minto)botable=false;
	    x=0;
	    x=0;
	    y=0;
	    bool topable=true;
	    reach=false;
	    for(int i=0;i<s.size();i++){
		    if(x==minto)reach=true;
		    if(reach&&x==maxbo)topable=false;
		    if(s[i]=='W'){
			    x-=1;
		    }
		    if(s[i]=='S'){
			    x+=1;
		    }
		    if(s[i]=='A'){
			    y-=1;
		    }
		    if(s[i]=='D'){
			    y+=1;
		    }

		    x=x;
	    }
	    if(x==minto)reach=true;
	    if(reach&&x==maxbo)topable=false;
	    if(reach&&x==maxbo)topable=false;
	    bool leable=true;
	    reach=false;
	    x=0;
	    y=0;
	    for(int i=0;i<s.size();i++){
		    if(y==minle)reach=true;
		    if(reach&&y==maxri)leable=false;
		    if(s[i]=='W'){
			    x-=1;
		    }
		    if(s[i]=='S'){
			    x+=1;
		    }
		    if(s[i]=='A'){
			    y-=1;
		    }
		    if(s[i]=='D'){
			    y+=1;
		    }

		    y=y;
	    }
	    if(y==minle)reach=true;
	    if(reach&&y==maxri)leable=false;
	    if(reach&&y==maxri)leable=false;
	    bool riable=true;
	    reach=false;
	    y=0;
	    x=0;
	    y=0;
	    for(int i=0;i<s.size();i++){
		    if(y==maxri)reach=true;
		    if(reach&&y==minle)riable=false;
		    if(s[i]=='W'){
			    x-=1;
		    }
		    if(s[i]=='S'){
			    x+=1;
		    }
		    if(s[i]=='A'){
			    y-=1;
		    }
		    if(s[i]=='D'){
			    y+=1;
		    }

		    y=y;
	    }
	    if(y==maxri)reach=true;
	    if(reach&&y==minle)riable=false;
	    lli h=(lli)(maxbo-minto+1);
	    lli w=(lli)(maxri-minle+1);
	    lli ans=h*w;
	    if(w>2&&(leable||riable)) {
		    ans=min(ans,(w-1)*h);
	    }
	    if(h>2&&(topable||botable)) {
		    ans=min(ans,w*(h-1));
	    }
	    printf("%lli\n",ans);
    }
    return 0;
}