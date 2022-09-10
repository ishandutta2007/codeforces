#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string tail[6]={"lios","liala","etr","etra","initis","inites"};
int judge(string str){
    for(int i=0;i<6;i++){
        if(str.substr(max(0,(int)(str.size()-tail[i].size())))==tail[i])return i;
    }
    return -1;
}
int main(){
    string str;
    int male=0,now=0,error=0,get=0,n=0,type;
    while(cin>>str){
        n++;
        type=judge(str);
        if(type==-1)error=-1;
        else if(type&1)male|=1;
        else male|=2;
        if(type<now)error=1;
        now=type;
        if(now==2||now==3){
            get=1;
            now+=2;
        }
    }
    if(n==1&&type!=-1){
        cout<<"YES"<<endl;
        return 0;
    }
    if(male==3||error||get==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}