#include<iostream>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
#define SIZE 1024
int ann;
struct data{
    int x,y,v;
}an[SIZE];
int in[SIZE],out[SIZE],value[SIZE];
main(){
    int n,p,x,y,v,i;
    cin>>n>>p;
    while(p--){
        cin>>x>>y>>v;
        in[y]=x;
        out[x]=y;
        value[x]=v;
    }
    for(i=1;i<=n;i++){
        if(!in[i]&&out[i]){
            x=i;
            y=value[i];
            while(out[x]){
                y=min(y,value[x]);
                x=out[x];
            }
            an[ann++]=(data){i,x,y};
        }
    }
    cout<<ann<<endl;
    for(i=0;i<ann;i++){
        cout<<an[i].x<<" " <<an[i].y<< " "<<an[i].v<<endl;
    }
}