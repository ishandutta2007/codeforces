#include<iostream>
#include<string>
#include<math.h>
#include<map>
using namespace std;
#define Err 1e-9
map<string,int>hash;
main(){
    int n,m,v,i;
    double k;
    string skill;
    cin>>n>>m>>k;
    for(i=0;i<n;i++){
        cin>>skill>>v;
        if((int)floor(v*k+Err)>=100){
            hash[skill]=(int)floor(v*k+Err);
        }
    }
    for(i=0;i<m;i++){
        cin>>skill;
        if(!hash.count(skill))hash[skill]=0;
    }
    cout<<hash.size()<<endl;
    map<string,int>::iterator it;
    for(it=hash.begin();it!=hash.end();it++)
        cout<< (it->first) << " " << (it->second)<<endl;
}