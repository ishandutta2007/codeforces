#include<iostream>
#include<string.h>
using namespace std;
int h[105],v[105];
bool can[105];
int n=0;
void dfs(int i){
    can[i]=true;
    for(int k=1;k<=n;k++){
        if(can[k])
            continue;
        if(h[i]>h[k] && h[i]<v[k])
            dfs(k);
        else
			if(v[i]>h[k] && v[i]<v[k])
            	dfs(k);
    }
}
int times;
int main(){
    cin>>times;
    for(int tim=1;tim<=times;tim++){
		int mode,x,y;
		cin>>mode;
		if(mode==1){
            n++;
            cin>>h[n];
            cin>>v[n];
        }
        if(mode==2){
            cin>>x;
            cin>>y;
            memset(can,0,sizeof(can));
            dfs(x);
            if(can[y])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}