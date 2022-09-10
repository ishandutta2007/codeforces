#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
vector<string>d;
string str;
bool mark(char c){
    if(c==' ')return 0;
    if(c>='a'&&c<='z')return 0;
    return 1;
}
int main(){
    int i,j,k,n;
    getline(cin,str);
    for(i=0;i<str.size();){
        if(mark(str[i])){
            d.pb(str.substr(i,1));
            i++;
        }
        else if(str[i]!=' '){
            for(j=0;i+j<str.size()&&!mark(str[i+j])&&str[i+j]!=' ';j++);
            d.pb(str.substr(i,j));
            i+=j;
        }
        else i++;
    }
    for(i=0;i<d.size();i++){
        if(mark(d[i][0]))cout<<d[i];
        else{
            if(i)cout<<" ";
            cout<<d[i];
        }
    }
    cout<<endl;
    return 0;
}