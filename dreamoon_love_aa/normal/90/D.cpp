#include<iostream>
#include<map>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;
struct data{
    long long type,x,y;
};
map<string,vector<string> >contain;
map<string,data>arg;
void Find(string str,long long &x,long long &y){
    data &X=arg[str];
    if(X.type==0){
        x=X.x;
        y=X.y;
        return;
    }
    long long xx,yy,anx=0,any=0;
    vector<string> &now=contain[str];
    if(now.size()==0){
        X=(data){0,0,0};
        x=y=0;
        return;
    }
    for(int i=0;i<now.size();i++){
        Find(now[i],xx,yy);
        if(X.type==1){
            anx=max(anx,xx);
            any+=yy;
        }
        else{
            any=max(any,yy);
            anx+=xx;
        }
    }
    anx+=X.x*2;
    any+=X.x*2;
    if(X.type==1)any+=X.y*(now.size()-1);
    else anx+=X.y*(now.size()-1);
    X=(data){0,anx,any};
    x=anx;
    y=any;
}
main(){
    int n;
    cin>>n;
    string input;
    string name;
    getline(cin,input);
    vector<string> empty_vector;
    while(n--){
        getline(cin,input);
        if(input[0]=='W'){
            int pos1=input.find('(');
            int pos2=input.find(',');
            int pos3=input.find(')');
            name=input.substr(7,pos1-7);
            arg[name]=(data){0,atoi(input.substr(pos1+1,pos2-pos1-1).c_str()),atoi(input.substr(pos2+1,pos3-pos2-1).c_str())};
            contain[name]=empty_vector;
        }
        else if(input[0]=='V'){
            name=input.substr(5);
            arg[name]=(data){1,0,0};
            contain[name]=empty_vector;
        }
        else if(input[0]=='H'){
            name=input.substr(5);
            arg[name]=(data){2,0,0};
            contain[name]=empty_vector;
        }
        else{
            int pos1=input.find('.');
            int pos2=input.find('(');
            int pos3=input.find(')');
            name=input.substr(0,pos1);
            if(!input.substr(pos1+1,pos2-pos1-1).compare("pack"))contain[name].push_back(input.substr(pos2+1,pos3-pos2-1));
            else{
                long long x=atoi(input.substr(pos2+1,pos3-pos2-1).c_str());
                if(input.substr(pos1+1,pos2-pos1-1).compare("set_border"))arg[name].y=x;
                else arg[name].x=x;
            }
        }
    }
    map<string,vector<string> >::iterator it;
    for(it=contain.begin();it!=contain.end();it++){
        cout<<it->first<<" ";
        long long x,y;
        Find(it->first,x,y);
        cout<<x<<" "<<y<<endl;
    }
}